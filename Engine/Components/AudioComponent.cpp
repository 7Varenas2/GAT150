#include "AudioComponent.h"
#include "Framework/Factory.h"
#include "Engine.h"

namespace neum
{
	AudioComponent::~AudioComponent()
	{
		Stop();
	}

	void AudioComponent::Update()
	{
	}

	void AudioComponent::Initialize()
	{
		if (m_play_on_start)
		{
			Play();
		}
	}

	void AudioComponent::Play()
	{
		m_channel = g_audioSystem.PlayAudio(m_soundname, m_volume, m_pitch, loop);
	}

	void AudioComponent::Stop()
	{
		m_channel.Stop();
	}


	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool AudioComponent::Read(const rapidjson::Value& value)
	{
		if (!value.HasMember("actors") || !value["actors"].IsArray())
		{
			return false;
		}

		for (auto& actorValue : value["actors"].GetArray())
		{
			std::string type;
			READ_DATA(actorValue, type);


			auto actor = Factory::Instance().Create<Actor>(type);
			if (actor)
			{
				// Read Actor
				actor->Read(actorValue);
			}
			return true;
		}
		g_audioSystem.AddAudio(m_soundname, m_soundname);
		return true;

	}

}

