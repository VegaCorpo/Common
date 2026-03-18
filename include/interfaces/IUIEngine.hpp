#pragma once

#include <functional>

#include "../types/RenderDataBuffer.hpp"

namespace common {
    class IUIEngine {

        using TextureLoader = std::function<unsigned int(unsigned char*, int, int)>;

        public:
            // Destructor
            virtual ~IUIEngine() = default;

            // Init methods that must be call by Core
            virtual void init() = 0;

            // Update UI frame and convert it for the renderer
            virtual void update(float dt, float w, float h) = 0;

            // Get Vertex Buffer
            virtual RenderDataBuffer getDataBuffer() = 0;

            virtual void renderUI(float dt, float w, float h) = 0;
    };
} // namespace ui
