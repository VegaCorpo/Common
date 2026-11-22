#pragma once

#include <cstdint>
#include <string>
#include <variant>
#include <vector>

namespace common {
    enum class DisplayOptionId : uint8_t
    {
        TRAILS,
        LABELS,
        ICONS,

        // END
        DISPLAY_OPTION_COUNT
    };

    /**
     * @brief Tunable parameter of a display option (e.g. the sampling interval of the trails)
     *
     * value holds both the type and the current value of the parameter.
     */
    struct DisplayOptionParam {
            std::string name;
            std::string description;
            std::variant<bool, int, float> value;
    }; // size 72 B

    /**
     * @brief Display option exposed by the renderer (trails, labels, ...)
     *
     * params stays empty when the option has nothing to tune.
     */
    struct DisplayOption {
            DisplayOptionId id = DisplayOptionId::DISPLAY_OPTION_COUNT;
            bool enabled = false;
            std::string name;
            std::string description;
            std::vector<DisplayOptionParam> params;
    }; // size 96 B fixed + 72 B by param
       // min: 96 B (p = 0) | max: 96 + 72 * p B
} // namespace common
