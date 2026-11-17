#pragma once

#include <cmath>
#include <cstddef>
#include <expected>

namespace common::integration {
    enum class TimeStepError
    {
        NOT_FINITE,
        NEGATIVE,
        ZERO_SUB_STEP,
        TOO_MANY_SUB_STEPS,
    };

    struct SubSteps {
            std::size_t count = 0;
            double duration = 0.0;

            [[nodiscard]] bool empty() const noexcept { return count == 0; }
    };

    class TimeStep {
        public:
            static constexpr double DEFAULT_MAX_SUB_STEP = 7200.0;
            static constexpr std::size_t MAX_SUB_STEP_COUNT = 10'000'000;

            TimeStep() = default;

            [[nodiscard]] static std::expected<TimeStep, TimeStepError> withMaxSubStep(double maxSubStep)
            {
                const std::expected<double, TimeStepError> validated = _validate(maxSubStep);

                if (!validated)
                    return std::unexpected(validated.error());
                if (*validated == 0.0)
                    return std::unexpected(TimeStepError::ZERO_SUB_STEP);
                return TimeStep(*validated);
            }

            [[nodiscard]] static std::expected<TimeStep, TimeStepError>
            forForceEvaluations(std::size_t evaluationsPerStep)
            {
                return withMaxSubStep(DEFAULT_MAX_SUB_STEP * static_cast<double>(evaluationsPerStep));
            }

            [[nodiscard]] std::expected<SubSteps, TimeStepError> split(double frameDuration) const
            {
                return _validate(frameDuration).and_then([this](double duration) { return this->_divide(duration); });
            }

            [[nodiscard]] double maxSubStep() const noexcept { return this->_maxSubStep; }

        private:
            explicit TimeStep(double maxSubStep) : _maxSubStep(maxSubStep) {}

            [[nodiscard]] static std::expected<double, TimeStepError> _validate(double duration)
            {
                if (!std::isfinite(duration))
                    return std::unexpected(TimeStepError::NOT_FINITE);
                if (duration < 0.0)
                    return std::unexpected(TimeStepError::NEGATIVE);
                return duration;
            }

            [[nodiscard]] std::expected<SubSteps, TimeStepError> _divide(double duration) const
            {
                const double count = std::ceil(duration / this->_maxSubStep);

                if (count > static_cast<double>(MAX_SUB_STEP_COUNT))
                    return std::unexpected(TimeStepError::TOO_MANY_SUB_STEPS);
                if (count == 0.0)
                    return SubSteps{};
                return SubSteps{static_cast<std::size_t>(count), duration / count};
            }

            double _maxSubStep = DEFAULT_MAX_SUB_STEP;
    };
} // namespace common::integration
