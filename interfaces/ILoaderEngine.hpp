#pragma once

#include <string>
#include "interfaces/IModule.hpp"
#include "types/types.hpp"

namespace common {
    class ILoaderEngine : public IModule {
        public:
            virtual common::LoaderStatus createScene(void* registry, const std::string& filename) = 0;

    };
} // namespace common
