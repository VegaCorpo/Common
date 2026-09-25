#pragma once

#include <functional>
#include <types/World.hpp>

#include "interfaces/IModule.hpp"
#include "types/RenderDataBuffer.hpp"

namespace common {

    using TextureLoader = std::function<unsigned int(unsigned char*, int, int)>;

    class IUIEngine : public IModule {

        public:
            // Init methods that must be call by Core
            virtual void init(void* windowHandle, common::SpecificDataUI &specificDataUI) = 0;

            // Update UI frame and convert it for the renderer
            virtual void update(float dt, float w, float h) = 0;

            // Get Vertex Buffer
            virtual RenderDataBuffer getDataBuffer() = 0;

            virtual void render() = 0;
    };
} // namespace ui
