#pragma once

#include <cstddef>
#include <optional>
#include "components/mass.hpp"
#include "components/name.hpp"
#include "components/position.hpp"
#include "components/radius.hpp"
#include "components/velocity.hpp"

namespace common {
    struct BodyPatch {
            std::size_t id;
            std::optional<common::components::Name> name = std::nullopt;
            std::optional<common::components::Mass> mass = std::nullopt;
            std::optional<common::components::Radius> radius = std::nullopt;
            std::optional<common::components::Position> position = std::nullopt;
            std::optional<common::components::Velocity> velocity = std::nullopt;
    };
} // namespace common
