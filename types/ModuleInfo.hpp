#pragma once

#include "types.hpp"

namespace common {
    struct ModuleInfo {
            const char* name;
            const char* version;
            common::ModuleType type;
    };
} // namespace common

extern "C" {
    const common::ModuleInfo* get_module_info();
}
