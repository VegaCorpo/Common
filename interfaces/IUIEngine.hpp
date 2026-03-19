#pragma once

#include <functional>

#include "../types/RenderDataBuffer.hpp"
#include <GLFW/glfw3.h>

namespace common {

    using TextureLoader = std::function<unsigned int(unsigned char*, int, int)>;
    
    class IUIEngine {

        public:
            // Destructor
            virtual ~IUIEngine() = default;

            // Init methods that must be call by Core
<<<<<<< HEAD
            virtual void init(GLFWwindow* window) = 0;
=======
            virtual void init(TextureLoader loader) = 0;
>>>>>>> 60766a9 (del: undo changes)

            // Update UI frame and convert it for the renderer
            virtual void update(float dt, float w, float h) = 0;

            // Get Vertex Buffer
            virtual RenderDataBuffer getDataBuffer() = 0;
<<<<<<< HEAD

            virtual void render() = 0;
=======
>>>>>>> 60766a9 (del: undo changes)
    };
} // namespace ui
