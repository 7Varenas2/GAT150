#pragma once
#pragma once
#include "../Framework/Component.h"
#include <string>

namespace neum
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;

		void Update() override;
		void Play();
		void Stop();

		std::string m_sound;
		bool m_playonawait;
		float m_volume = 1.0f;
		float m_pitch = 1.0f;


	};
}