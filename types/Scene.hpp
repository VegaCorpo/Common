#pragma once

#include <cstddef>
#include <vector>
#include "components/acceleration.hpp"
#include "components/angularVelocity.hpp"
#include "components/mass.hpp"
#include "components/name.hpp"
#include "components/orientation.hpp"
#include "components/position.hpp"
#include "components/radius.hpp"
#include "components/texture.hpp"
#include "components/velocity.hpp"
#include "types.hpp"

namespace common {
    struct BodyDescription {
            std::size_t id;
            common::components::Name name;
            common::components::Position position;
            common::components::Velocity velocity;
            common::components::Acceleration acceleration;
            common::components::Mass mass;
            common::components::Radius radius;
            common::components::Texture texture;
            common::components::Orientation orientation;
            common::components::AngularVelocity angularVelocity;
    };

    struct SceneDescription {
            std::vector<common::BodyDescription> bodies;
            common::IntegratorType integrator = common::DEFAULT_INTEGRATOR;
    };
} // namespace common
