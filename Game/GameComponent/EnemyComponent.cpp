#include "EnemyComponent.h"
#include "Engine.h"
#include <iostream>

void EnemyComponent::Initialize()
{
    CharacterComponent::Initialize();
}

void EnemyComponent::Update()
{
    auto actor = m_owner->GetScene()->GetActorFromName("Player");
    if (actor)
    {
        neum::Vector2 direction = actor->m_transform.position - m_owner->m_transform.position;
        neum::Vector2 force = direction.Normalized() * speed;

        auto component = m_owner->GetComponent<neum::PhysicsComponent>();
        if (component) component->ApplyForce(force);
    }
}

void EnemyComponent::OnCollisionEnter(neum::Actor* other)
{
    if (other->GetTag() == "Player")
    {
        neum::g_eventManager.Notify({ "EVENT_DAMAGE", other, damage });
    }
}

void EnemyComponent::OnCollisionExit(neum::Actor* other)
{
}

void EnemyComponent::OnNotify(const neum::Event& event)
{
    if (event.name == "EVENT_DAMAGE")
    {
        health -= std::get<float>(event.data);
        if (health <= 0)
        {
            m_owner->SetDestroy();
        }
    }

}

bool EnemyComponent::Write(const rapidjson::Value& value) const
{
    return true;
}

bool EnemyComponent::Read(const rapidjson::Value& value)
{
    CharacterComponent::Read(value);

    return true;
}
