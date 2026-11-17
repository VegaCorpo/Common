#pragma once

namespace common::integration {
    template <typename State>
    class IAccelerationField {
        public:
            virtual ~IAccelerationField() = default;

            virtual void compute(State& state) = 0;
    };
} // namespace common::integration
