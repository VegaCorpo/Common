#pragma once

#include <entt/entt.hpp>
#include "../types/RenderDataBuffer.hpp"

namespace common {
    class IRenderEngine {
        public:
            virtual ~IRenderEngine() = default;

            /**
             * @brief Initialize the rendering engine
             */
            virtual void init() = 0;

            /**
             * @brief Is the rendering engine still running
             *
             * @return true if running false otherwise
             */
            [[nodiscard]] virtual bool isRunning() const = 0;

            /**
             * @brief Get the window handle
             *
             * @return void* to the window
             */
            virtual void* getWindowHandle() = 0;

            /**
             * @brief update the vertex buffer
             *
             * @param vertexBuffer the elements to be drawn
             */
            virtual void setVertexBuffer(common::RenderDataBuffer& renderDataBuffer) = 0;

            /**
             * @brief update the rendering engine
             */
            virtual void update(entt::registry& registry) = 0;

            /**
             * @brief render the current scene
             */
            virtual void render() = 0;
    };
} // namespace common
