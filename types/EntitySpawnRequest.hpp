#pragma once

#include <string>

#include "components/acceleration.hpp"
#include "components/mass.hpp"
#include "components/orientation.hpp"
#include "components/position.hpp"
#include "components/radius.hpp"
#include "components/velocity.hpp"
#include "components/name.hpp"

namespace common {

    struct EntitySpawnRequest {
        common::components::Name name;
        common::components::Mass mass;
        common::components::Radius radius;
        common::components::Position position;
        common::components::Velocity velocity;
        common::components::Acceleration acceleration;
        common::components::Orientation orientation;

    };

} // namespace ui