#pragma once

#include <cstddef>
#include "integration/IAccelerationField.hpp"

namespace common::integration {
    template <typename Bodies, typename State = Bodies>
    class IIntegrator {
        public:
            virtual ~IIntegrator() = default;

            virtual void step(const Bodies& bodies, IAccelerationField<State>& field, double duration) const = 0;
            [[nodiscard]] virtual std::size_t forceEvaluationsPerStep() const noexcept = 0;
    };
} // namespace common::integration
