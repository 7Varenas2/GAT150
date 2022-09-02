#include "InputSystem.h"
#include <SDL.h>
#include <iostream>

namespace neum 
{
	extern const uint32_t key_space = SDL_SCANCODE_SPACE;
	extern const uint32_t key_up = SDL_SCANCODE_W;
	extern const uint32_t key_down = SDL_SCANCODE_S;
	extern const uint32_t key_left = SDL_SCANCODE_A;
	extern const uint32_t key_right = SDL_SCANCODE_D;
	extern const uint32_t key_escape = SDL_SCANCODE_ESCAPE;
	extern const uint32_t key_enter = SDL_SCANCODE_RETURN;

	const uint32_t button_left = 0;
	const uint32_t button_middle = 1;
	const uint32_t button_right = 2;

	void InputSystem::Initialize()
	{
		const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys);
		m_keyboardState.resize(m_numKeys);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		m_prevKeyboardState = m_keyboardState;
	}

	void InputSystem::Shutdown()
	{
		//
	}
	void InputSystem::Update()
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		//save previous state
		m_prevKeyboardState = m_keyboardState;

		//get current state
		const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());


		m_prevmouseButtonState = m_mouseButtonState;
		int x, y;
		uint32_t buttons = SDL_GetMouseState(&x, &y);
		m_mousePosition = neum::Vector2{ (float)x , (float)y };
	}


	InputSystem::State InputSystem::GetKeyState(uint32_t key)
	{
		State keyState = State::Idle;
		bool keyDown = GetKeyDown(key);
		bool prevKeyDown = GetPreviousKeyDown(key);
		// set the keyState if keyDown (true) and prevKeyDown (true)
		if (keyDown == true && prevKeyDown == true)
		{
			keyState = State::Held;

		}
		else if (keyDown == false && prevKeyDown == false)
		{
			keyState = State::Idle;

		}
		else if (keyDown == true && prevKeyDown == false)
		{
			keyState = State::Pressed;

		}
		else if (keyDown == false && prevKeyDown == true)
		{
			keyState = State::Released;
		}

		return keyState;
	}



	InputSystem::State InputSystem::GetButtonState(uint32_t button)
	{
		State keyState = State::Idle;
		bool buttonDown = GetButtonDown(button);
		bool prevButtonDown = GetPreviousButtonDown(button);
		
		if (buttonDown == true && prevButtonDown == true)
		{
			keyState = State::Held;
		}
		else if (buttonDown == true && prevButtonDown == false)
		{
			keyState = State::Idle;
		}
		else if (buttonDown == false && prevButtonDown == true)
		{
			keyState = State::Pressed;
		}
		else if (buttonDown == false && prevButtonDown == false)
		{
			keyState = State::Idle;
		}
		// fill in the remaining states
		return keyState;
	}
}