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

    enum class Action
    {
        // Renderer Actions
        MOVE_CAMERA_FORWARD,
        MOVE_CAMERA_BACKWARD,
        MOVE_CAMERA_LEFT,
        MOVE_CAMERA_RIGHT,
        MOVE_CAMERA_UP,
        MOVE_CAMERA_DOWN,
        ROTATE_CAMERA_UP,
        ROTATE_CAMERA_DOWN,
        ROTATE_CAMERA_LEFT,
        ROTATE_CAMERA_RIGHT,
        CHANGE_RESCALE_MODE,

        // UI Actions
        CHANGE_SELECTION,
        CHANGE_SELECTION_REVERSED,
    };
} // namespace common
