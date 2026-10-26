#include <components/radius.hpp>
#include "EntityPreset.hpp"
#include "PhysicalConstant.hpp"

#include <array>

namespace common::presets {

inline constexpr EntityPreset SUN   {"Sun",   constants::SUN_MASS, constants::SUN_RADIUS};
inline constexpr EntityPreset EARTH {"Earth", constants::EARTH_MASS, constants::EARTH_RADIUS};
inline constexpr EntityPreset MERCURY {"Mercury", constants::MERCURY_MASS, constants::MERCURY_RADIUS};
inline constexpr EntityPreset VENUS {"Venus", constants::VENUS_MASS, constants::VENUS_RADIUS};
inline constexpr EntityPreset MOON {"Moon", constants::MOON_MASS, constants::MOON_RADIUS};
inline constexpr EntityPreset MARS {"Mars", constants::MARS_MASS, constants::MARS_RADIUS};
inline constexpr EntityPreset JUPITER {"Jupiter", constants::JUPITER_MASS, constants::JUPITER_RADIUS};
inline constexpr EntityPreset SATURN {"Saturn", constants::SATURN_MASS, constants::SATURN_RADIUS};
inline constexpr EntityPreset URANUS {"Uranus", constants::URANUS_MASS, constants::URANUS_RADIUS};
inline constexpr EntityPreset NEPTUNE {"Neptune", constants::NEPTUNE_MASS, constants::NEPTUNE_RADIUS};

inline constexpr std::array PRESET = {
    SUN, MERCURY, VENUS, EARTH, MOON, MARS, JUPITER, SATURN, URANUS, NEPTUNE
};

} // namespace common::presets