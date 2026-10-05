#pragma once

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

namespace common {
    struct WorldState {
            std::vector<size_t> entitiesId;
            std::vector<common::components::Position> positions;
            std::vector<common::components::Velocity> velocities;
            std::vector<common::components::Acceleration> accelerations;
            std::vector<common::components::Radius> radius;
            std::vector<bool> collided;
            std::vector<common::components::Orientation> orientations;
    }; // size 80 B by entity

    struct SpecificDataPhysics {
            std::vector<size_t> entitiesId;
            std::vector<common::components::Mass> masses;
            std::vector<common::components::Position> positions;
            std::vector<common::components::Velocity> velocities;
            std::vector<common::components::Acceleration> accelerations;
            std::vector<common::components::Radius> radius;
            std::vector<common::components::Orientation> orientations;
            std::vector<common::components::AngularVelocity> angularVelocities;
            double epsilon = 0;
    }; // size 88 B by entity

    struct SpecificDataRender {
            std::vector<size_t> entitiesId;
            std::vector<common::components::Name> names;
            std::vector<common::components::Radius> radius;
            std::vector<common::components::Texture> textures;
    }; // size 112 B by entity

    struct SpecificDataUI {
            std::vector<size_t> entitiesId;
            std::vector<common::components::Name> names;
            std::vector<common::components::Mass> masses;
    }; // size 66 B by entity
} // namespace common
