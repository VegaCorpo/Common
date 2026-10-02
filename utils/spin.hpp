#pragma once

#include <cmath>
#include <numbers>
#include "utils/rotation.hpp"

namespace common::rotation {
    struct SpinParameters {
            double period = 0;
            double obliquity = 0;
            double axisAzimuth = 0;
            double initialAngle = 0;
    };

    inline constexpr Axis BODY_SPIN_AXIS{0.0, 0.0, 1.0};
    inline constexpr double FULL_TURN = 2.0 * std::numbers::pi;

    [[nodiscard]] inline Axis spinAxisOf(const SpinParameters& spin) noexcept
    {
        return {std::sin(spin.obliquity) * std::cos(spin.axisAzimuth),
                std::sin(spin.obliquity) * std::sin(spin.axisAzimuth), std::cos(spin.obliquity)};
    }

    [[nodiscard]] inline Axis tiltAxisOf(const SpinParameters& spin) noexcept
    {
        return {-std::sin(spin.axisAzimuth), std::cos(spin.axisAzimuth), 0.0};
    }

    [[nodiscard]] inline double spinRateOf(const SpinParameters& spin) noexcept
    {
        if (spin.period == 0.0)
            return 0.0;
        return FULL_TURN / spin.period;
    }

    [[nodiscard]] inline Orientation initialOrientation(const SpinParameters& spin) noexcept
    {
        const Orientation tilt = fromAxisAngle(tiltAxisOf(spin), spin.obliquity);
        const Orientation phase = fromAxisAngle(BODY_SPIN_AXIS, spin.initialAngle);

        return normalized(compose(tilt, phase));
    }

    [[nodiscard]] inline AngularVelocity angularVelocity(const SpinParameters& spin) noexcept
    {
        const Axis axis = spinAxisOf(spin);
        const double rate = spinRateOf(spin);

        return {axis.x * rate, axis.y * rate, axis.z * rate};
    }
} // namespace common::rotation
