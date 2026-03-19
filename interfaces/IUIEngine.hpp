#pragma once

#include <functional>

#include "../types/RenderDataBuffer.hpp"

namespace common {

    using TextureLoader = std::function<unsigned int(unsigned char*, int, int)>;
    
    class IUIEngine {

        public:
            // Destructor
            virtual ~IUIEngine() = default;

            // Init methods that must be call by Core
            virtual void init(void* windowHandle) = 0;

            // Update UI frame and convert it for the renderer
            virtual void update(float dt, float w, float h) = 0;

            // Get Vertex Buffer
            virtual RenderDataBuffer getDataBuffer() = 0;

            virtual void render() = 0;
    };
} // namespace ui
