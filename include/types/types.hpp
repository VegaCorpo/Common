#pragma once

namespace common {
    enum class ModuleType
    {
        PHYSICS,
        RENDERER,
        UI,
        INPUTS,
        LOADER
    };

    enum class LoaderStatus
    {
        SUCCESS,
        FAILED_TO_OPEN_FILESTREAM,
        WRONG_SIMULATION_FORMAT
    };

    enum class Action {
        MOVE_CAMERA_UP,
        MOVE_CAMERA_DOWN,
        MOVE_CAMERA_RIGHT,
        MOVE_CAMERA_LEFT,
        CHANGE_SELECTION,
        CHANGE_SELECTION_REVERSED
    };
}
