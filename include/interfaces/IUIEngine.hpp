#pragma once

namespace common {
    class IUIEngine {

        public:
            // Destructor
            virtual ~IUIEngine() = default;

            virtual void init() = 0;

            // Update UI frame and convert it for the renderer
            virtual void update(float dt, float w, float h) = 0;
    };
} // namespace ui
