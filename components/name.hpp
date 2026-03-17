#pragma once

namespace common::components {
    static constexpr unsigned char MAX_NAME_LENGTH = 50;
    struct Name {
            char value[MAX_NAME_LENGTH];
    };
} // namespace common::components
