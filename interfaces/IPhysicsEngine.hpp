#pragma once

#include <string>
#include "interfaces/IModule.hpp"
#include "types/World.hpp"

namespace common {
    class IPhysicsEngine : public IModule {
        public:
            virtual void init(common::SpecificDataPhysics) = 0;
            virtual void update(double dt) = 0;
            virtual void shutdown() = 0;
            virtual void syncIn(common::SpecificDataPhysics) = 0;
            virtual common::WorldState publish() = 0;

            [[nodiscard]] virtual std::string getName() const = 0;
    };
} // namespace common
