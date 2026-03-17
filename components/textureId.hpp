#pragma once

namespace common::components {
    static constexpr unsigned char MAX_TEXTURE_ID_LENGTH = 50;
    struct TextureId {
            char value[MAX_TEXTURE_ID_LENGTH];
    };
} // namespace common::components
