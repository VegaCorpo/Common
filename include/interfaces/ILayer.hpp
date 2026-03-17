#pragma once
#include <types/RenderDataBuffer.hpp>
#include <interfaces/IUIEngine.hpp>

namespace ui {
    class ILayer {
        public:

            virtual ~ILayer() = default;

            virtual void init() = 0;

            virtual void renderFrame(float deltaTime, float width, float height) = 0;

            virtual void shutdown() = 0;
    };
} // namespace ui