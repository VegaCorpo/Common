#pragma once

namespace common::math {
    struct Vector3 {
            double x = 0.0;
            double y = 0.0;
            double z = 0.0;

            constexpr Vector3& operator+=(const Vector3& other) noexcept
            {
                x += other.x;
                y += other.y;
                z += other.z;
                return *this;
            }

            [[nodiscard]] friend constexpr Vector3 operator+(const Vector3& left, const Vector3& right) noexcept
            {
                return {left.x + right.x, left.y + right.y, left.z + right.z};
            }

            [[nodiscard]] friend constexpr Vector3 operator-(const Vector3& left, const Vector3& right) noexcept
            {
                return {left.x - right.x, left.y - right.y, left.z - right.z};
            }

            [[nodiscard]] friend constexpr Vector3 operator*(const Vector3& vector, double scalar) noexcept
            {
                return {vector.x * scalar, vector.y * scalar, vector.z * scalar};
            }

            [[nodiscard]] friend constexpr Vector3 operator/(const Vector3& vector, double scalar) noexcept
            {
                return {vector.x / scalar, vector.y / scalar, vector.z / scalar};
            }
    };

    [[nodiscard]] constexpr double dot(const Vector3& left, const Vector3& right) noexcept
    {
        return left.x * right.x + left.y * right.y + left.z * right.z;
    }

    [[nodiscard]] constexpr double squaredNorm(const Vector3& vector) noexcept
    {
        return dot(vector, vector);
    }
} // namespace common::math
