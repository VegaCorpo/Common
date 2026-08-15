#pragma once

#include <string>
#include "../types/World.hpp"

namespace common {
    class IPhysicsEngine {
        public:
            virtual ~IPhysicsEngine() = default;

            virtual void init(common::WorldState) = 0;
            virtual void update(double dt) = 0;
            virtual void shutdown() = 0;
            virtual void syncIn() = 0;
            virtual void syncOut() = 0;

            [[nodiscard]] virtual std::string getName() const = 0;
    };
} // namespace common
