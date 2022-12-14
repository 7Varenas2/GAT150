#include "RBPhysicsComponent.h"
#include "Engine.h"

namespace neum {

   RBPhysicsComponent::~RBPhysicsComponent()
    {
        if (m_body)
        {
            m_body->SetEnabled(false);
            g_physicsSystem.DestroyBody(m_body);
            
        }
    }

    void RBPhysicsComponent::Initialize()
    {
        m_body = g_physicsSystem.CreateBody(m_owner->m_transform.position, m_owner->m_transform.rotation, data);
        m_body->SetGravityScale(data.gravity_scale);
        m_body->SetLinearDamping(damping);

    }

    void RBPhysicsComponent::Update()
    {
        Vector2 position = B2VEC2_TO_VECTOR2(m_body->GetPosition());
        m_owner->m_transform.position = PhysicsSystem::WorldToScreen(position);
        m_owner->m_transform.rotation = math::RadToDeg(m_body->GetAngle());

        velocity = m_body->GetLinearVelocity();
    }

    void neum::RBPhysicsComponent::ApplyForce(const Vector2& force)
    {
        b2Vec2 v{ force.x , force.y };
        m_body->ApplyForceToCenter(v, true);
    }

    bool neum::RBPhysicsComponent::Write(const rapidjson::Value& value) const
    {
        return true;
    }

    bool neum::RBPhysicsComponent::Read(const rapidjson::Value& value)
    {
        PhysicsComponent::Read(value);

        READ_DATA(value, data.gravity_scale);
        READ_DATA(value, data.constrain_angle);
        READ_DATA(value, data.is_dynamic);

        return true;
    }
}
