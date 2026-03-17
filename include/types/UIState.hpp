#pragma once
#include <mutex>

namespace common {
    struct UIState {
        bool firstButtonPressed = false;
        bool secondButtonPressed = false;
    };

    struct SharedUIState {
        UIState state;
        std::mutex mutex;
    };
} // namespace common