#pragma once

#include <algorithm>
#include <cmath>
#include <vector>
#include "components/angularVelocity.hpp"
#include "components/orientation.hpp"

namespace common::rotation {
    using components::AngularVelocity;
    using components::Orientation;

    struct Axis {
            double x = 0;
            double y = 0;
            double z = 1;
    };

    [[nodiscard]] inline Orientation compose(const Orientation& outer, const Orientation& inner) noexcept
    {
        return {
            outer.scalar * inner.scalar - outer.x * inner.x - outer.y * inner.y - outer.z * inner.z,
            outer.scalar * inner.x + outer.x * inner.scalar + outer.y * inner.z - outer.z * inner.y,
            outer.scalar * inner.y - outer.x * inner.z + outer.y * inner.scalar + outer.z * inner.x,
            outer.scalar * inner.z + outer.x * inner.y - outer.y * inner.x + outer.z * inner.scalar,
        };
    }

    [[nodiscard]] inline double length(const Orientation& orientation) noexcept
    {
        return std::sqrt(orientation.scalar * orientation.scalar + orientation.x * orientation.x +
                         orientation.y * orientation.y + orientation.z * orientation.z);
    }

    [[nodiscard]] inline Orientation normalized(const Orientation& orientation) noexcept
    {
        const double orientationLength = length(orientation);
        if (orientationLength == 0.0)
            return {};
        return {orientation.scalar / orientationLength, orientation.x / orientationLength,
                orientation.y / orientationLength, orientation.z / orientationLength};
    }

    [[nodiscard]] inline Orientation fromAxisAngle(const Axis& axis, double angle) noexcept
    {
        const double halfAngleSine = std::sin(0.5 * angle);
        return {std::cos(0.5 * angle), axis.x * halfAngleSine, axis.y * halfAngleSine, axis.z * halfAngleSine};
    }

    [[nodiscard]] inline double spinRate(const AngularVelocity& angularVelocity) noexcept
    {
        return std::hypot(angularVelocity.x, angularVelocity.y, angularVelocity.z);
    }

    [[nodiscard]] inline Axis spinAxis(const AngularVelocity& angularVelocity, double rate) noexcept
    {
        return {angularVelocity.x / rate, angularVelocity.y / rate, angularVelocity.z / rate};
    }

    [[nodiscard]] inline Orientation advance(const Orientation& orientation, const AngularVelocity& angularVelocity,
                                             double duration) noexcept
    {
        const double rate = spinRate(angularVelocity);
        if (rate == 0.0)
            return orientation;
        const Orientation turn = fromAxisAngle(spinAxis(angularVelocity, rate), rate * duration);
        return normalized(compose(turn, orientation));
    }

    inline void advanceAll(std::vector<Orientation>& orientations,
                           const std::vector<AngularVelocity>& angularVelocities, double duration) noexcept
    {
        const std::size_t count = std::min(orientations.size(), angularVelocities.size());
        for (std::size_t index = 0; index < count; index += 1)
            orientations[index] = advance(orientations[index], angularVelocities[index], duration);
    }
} // namespace common::rotation
