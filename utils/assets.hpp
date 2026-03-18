#pragma once

#include "../components/textureId.hpp"
#include <string>

namespace common {
    inline const std::string ASSETS_PATH = "Renderer/assets/";
    inline const std::string TEXTURE_PATH = ASSETS_PATH + "textures/";

    constexpr char DEFAULT_TEXTURE_PATH[components::MAX_TEXTURE_PATH_LENGTH] = "missing_texture.jpg";
} // namespace common
