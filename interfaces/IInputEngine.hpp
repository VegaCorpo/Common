#pragma once

#include "interfaces/IModule.hpp"

namespace common {
    class IInputEngine : public IModule {

        public:
            virtual void init() = 0;

            virtual void update() = 0;
    };
} // namespace inputs
