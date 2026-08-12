#pragma once

#include <vector>
#include "../components/position.hpp"
#include "../components/velocity.hpp"
#include "../components/acceleration.hpp"
#include "../components/mass.hpp"

namespace common {
    struct WorldState {
        std::vector<size_t> entities;
        std::vector<common::components::Position> positions;
        std::vector<common::components::Velocity> velocities;
        std::vector<common::components::Acceleration> accelerations;
        std::vector<common::components::Mass> mass;
    };
}
