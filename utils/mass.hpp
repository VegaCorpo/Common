#pragma once

#include <cmath>
#include "components/mass.hpp"

namespace common::mass {
    inline constexpr double MASS_EXPONENT_BASE = 10.0;

    [[nodiscard]] inline double toKilograms(const components::Mass& mass)
    {
        return static_cast<double>(mass.mantissa) * std::pow(MASS_EXPONENT_BASE, mass.exponent);
    }
} // namespace common::mass
