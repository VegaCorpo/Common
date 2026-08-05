#pragma once

#include <entt/entt.hpp>

namespace Physics {
    class IPhysicsEngine {
        public:
            virtual ~IPhysicsEngine() = default;

            virtual void init(entt::registry& registry, entt::dispatcher& dispatcher) = 0;
            virtual void update(entt::registry& registry, entt::dispatcher& dispatcher, double dt) = 0;
            virtual void shutdown(entt::registry& registry) = 0;
            virtual void syncIn(entt::registry& registry) = 0;
            virtual void syncOut(entt::registry& registry) = 0;

            [[nodiscard]] virtual std::string getName() const = 0;
    };
}
