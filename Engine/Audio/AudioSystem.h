#pragma once
#include "AudioChannel.h"
#include <map>
#include <iostream>
#include <string>

namespace FMOD
{
	class System;
	class Sound;
}

namespace neum
{
	class AudioSystem
	{
	public:
		AudioSystem() = default;
		~AudioSystem() = default;

		void Initialize();
		void Shutdown();
		
		void Update();

		void AddAudio(const std::string& name, const std::string& filename);
		AudioChannel PlayAudio(const std::string& name, float volume = 1, float pitch = 1, bool loop = false);
		

	private:
		FMOD::System* m_fmodSystem = nullptr;
		std::map<std::string, FMOD::Sound*> m_sounds;
	};
}
