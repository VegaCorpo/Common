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

    enum class ModuleState
    {
        PAUSE,
        RUNNING,
        END,
    };

    enum class LoaderStatus
    {
        SUCCESS,
        FAILED_TO_OPEN_FILESTREAM,
        WRONG_SIMULATION_FORMAT
    };

    enum class IntegratorType
    {
        VERLET,
        PEFRL,
    };

    inline constexpr IntegratorType DEFAULT_INTEGRATOR = IntegratorType::PEFRL;

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
        ROTATE_CAMERA_MOUSE,
        CHANGE_RESCALE_MODE,

        // UI Actions
        CHANGE_SELECTION,
        CHANGE_SELECTION_REVERSED,

        // END
        ACTION_COUNT
    };

    /**
     * @brief Action emitted by the inputs module
     *
     * x and y carry the action's value when it needs one (e.g. mouse delta in pixels for ROTATE_CAMERA_MOUSE),
     * they are 0 otherwise.
     */
    struct InputAction {
            Action action = Action::ACTION_COUNT;
            float x = 0.0f;
            float y = 0.0f;
    };
} // namespace common
