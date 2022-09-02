#include "EventManager.h"

void neum::EventManager::Initialize()
{
	//
}

void neum::EventManager::Shutdown()
{
	//
}

void neum::EventManager::Update()
{
	//
}

void neum::EventManager::Subscribe(const std::string& name, Event::functionPtr function, GameObject* receiver)
{
	Observer observer;
	observer.receiver = receiver;
	observer.function = function;
	
	m_events[name].push_back(observer);
}

void neum::EventManager::Unsubscribe(const std::string& name, GameObject* receiver)
{
	//
}

void neum::EventManager::Notify(const Event& event_)
{
	auto& observers = m_events[event_.name];
	for (auto& observer : observers)
	{
		if (event_.receiver == nullptr || event_.receiver == observer.receiver)
		{
			observer.function(event_);
		}
	}

}
