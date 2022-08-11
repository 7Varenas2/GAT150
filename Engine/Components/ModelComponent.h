#pragma once
#include "../Framework/Component.h"
#include "RenderComponent.h"
#include <iostream>

namespace neum
{
    class Model;

    class ModelComponent : public RenderComponent
    {
    public:
        virtual void Update() override;
        virtual void Draw(Renderer& renderer) override;

    public:
        std::shared_ptr<Model> m_model;

    };

}
