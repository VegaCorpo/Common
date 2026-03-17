#pragma once

#include "../components/textureId.hpp"
#include <string>
#include <unordered_map>

namespace common {
    std::string ASSETS_PATH = "Renderer/assets/";
    std::string TEXTURE_PATH = ASSETS_PATH + "textures/";

    constexpr char DEFAULT_TEXTURE_ID[components::MAX_TEXTURE_ID_LENGTH] = "Default";

    const std::unordered_map<std::string, std::string> textureMap = {
        {"Sun", TEXTURE_PATH + "sun.jpg"},
        {"Earth", TEXTURE_PATH + "earth.jpg"},
        {"Moon", TEXTURE_PATH + "moon.jpg"}
    };
} // namespace common
