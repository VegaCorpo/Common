#pragma once

namespace common::components {
    static constexpr unsigned char MAX_TEXTURE_PATH_LENGTH = 50;
    struct Texture {
            char path[MAX_TEXTURE_PATH_LENGTH];
    };
} // namespace common::components
