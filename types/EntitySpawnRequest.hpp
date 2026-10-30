#pragma once

#include <cstdio>
#include "components/acceleration.hpp"
#include "components/mass.hpp"
#include "components/name.hpp"
#include "components/orientation.hpp"
#include "components/position.hpp"
#include "components/radius.hpp"
#include "components/velocity.hpp"
#include "preset/EntityPreset.hpp"

namespace common {
    struct EntitySpawnRequest {
        common::components::Name name;
        common::components::Mass mass;
        common::components::Radius radius;
        common::components::Position position;
        common::components::Velocity velocity;
        common::components::Acceleration acceleration;
        common::components::Orientation orientation;

        static EntitySpawnRequest fromPreset(const common::EntityPreset &preset);
    };

    inline EntitySpawnRequest EntitySpawnRequest::fromPreset(const common::EntityPreset &preset)
    {
        EntitySpawnRequest request{};

        std::snprintf(request.name.value, sizeof(request.name.value), "%s", preset.label);
        request.mass         = preset.mass;
        request.radius       = preset.radius;
        request.position     = preset.position;
        request.velocity     = preset.velocity;
        request.acceleration = preset.acceleration;
        request.orientation  = preset.orientation;

        return request;
    }
}
