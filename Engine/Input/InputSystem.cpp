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

		// Save previous keyboard state
		m_prevKeyboardState = m_keyboardState;

		// Get current keyboard save
		const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		//std::cout << (bool)m_keyboardState[SDL_SCANCODE_SPACE] << std::endl;

		// Mouse
		m_prevmouseButtonState = m_mouseButtonState;
		int x, y;
		uint32_t buttons = SDL_GetMouseState(&x, &y);
		m_mousePosition = neum::Vector2{ x, y };
		m_mouseButtonState[0] = buttons & SDL_BUTTON_LMASK; // buttons [0001] & [0RML]
		m_mouseButtonState[1] = buttons & SDL_BUTTON_MMASK; // buttons [0010] & [0RML]
		m_mouseButtonState[2] = buttons & SDL_BUTTON_RMASK; // buttons [0100] & [0RML]

	}

	InputSystem::State InputSystem::GetButtonState(uint32_t button)
	{
		State keyState = InputSystem::State::Idle;
		bool buttonDown = GetButtonDown(button);
		bool prevButtonDown = GetPreviousButtonDown(button);

		// Set the State if buttonDown(true) and prevButtonDown (true)
		// fill in the remaining states
		if (buttonDown == (true) && prevButtonDown == (true)) 
		{
			
		}

		return State();
	}
}