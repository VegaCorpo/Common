#pragma once

#include "components/position.hpp"

namespace common::interpolation {
    using components::Position;

    [[nodiscard]] inline Position lerp(const Position& from, const Position& to, double progress) noexcept
    {
        return {
            from.x + (to.x - from.x) * progress,
            from.y + (to.y - from.y) * progress,
            from.z + (to.z - from.z) * progress,
        };
    }
} // namespace common::interpolation
