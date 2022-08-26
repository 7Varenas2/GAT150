#pragma once
#pragma once
#include "Framework/Component.h"
#include "Audio/AudioChannel.h"
#include <string>

namespace neum
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;
		~AudioComponent();

		CLASS_DECLARATION(AudioComponent)

		virtual void Initialize() override;
		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Play();
		void Stop();

	public:
		AudioChannel m_channel;

		std::string m_soundname;
		float m_volume = 1.0f;
		float m_pitch = 1.0f;
		bool m_play_on_start = false;
		bool loop= false;


	};
}