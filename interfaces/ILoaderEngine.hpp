#pragma once


#include <string>
#include "types/types.hpp"
namespace common {
    class ILoaderEngine {
        public:
            virtual ~ILoaderEngine() = default;

            virtual common::LoaderStatus createScene(void* registry, const std::string& filename) = 0;

    };
} // namespace common
