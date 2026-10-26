#pragma once
#include "components/acceleration.hpp"
#include "components/mass.hpp"
#include "components/orientation.hpp"
#include "components/position.hpp"
#include "components/radius.hpp"
#include "components/velocity.hpp"

namespace common {

    struct EntityPreset {
        const char *label;
        components::Mass mass;
        components::Radius radius;
        components::Position position;
        components::Velocity velocity;
        components::Acceleration acceleration;
        components::Orientation orientation;
    };

} // namespace common