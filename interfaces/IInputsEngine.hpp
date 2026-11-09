#pragma once

#include <queue>
#include "interfaces/IModule.hpp"
#include "types/types.hpp"

namespace common {
    class IInputsEngine : public IModule {
        public:
            [[nodiscard]] virtual bool init(void* windowHandle) = 0;
            [[nodiscard]] virtual std::queue<common::Action> poll() = 0;
    };
} // namespace common
