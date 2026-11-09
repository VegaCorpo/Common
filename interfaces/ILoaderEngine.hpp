#pragma once

#include <expected>
#include <string>
#include "interfaces/IModule.hpp"
#include "types/Scene.hpp"
#include "types/types.hpp"

namespace common {
    class ILoaderEngine : public IModule {
        public:
            [[nodiscard]] virtual std::expected<common::SceneDescription, common::LoaderStatus>
                createScene(const std::string& filename) = 0;
    };
} // namespace common
