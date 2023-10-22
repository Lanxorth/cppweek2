#pragma once
#include <iostream>
#include <cmath>

template <typename T, typename U>
class Vector2 {
public:
    T x;
    U y;

    // Constructors
    Vector2() : x(0), y(0) {}
    Vector2(T x, U y) : x(x), y(y) {}

    // Basic arithmetic operations
    Vector2<T, U> operator+(const Vector2& other) const {
        return Vector2<T, U>(x + other.x, y + other.y);
    }

    Vector2<T, U> operator-(const Vector2& other) const {
        return Vector2<T, U>(x - other.x, y - other.y);
    }

    Vector2<T, U> operator*(T scalar) const {
        return Vector2<T, U>(x * scalar, y * scalar);
    }

    Vector2<T, U> operator/(T scalar) const {
        if (scalar != 0) {
            return Vector2<T, U>(x / scalar, y / scalar);
        }
        else {
            std::cerr << "Division by zero." << std::endl;
            return *this;
        }
    }

    Vector2<T, U> operator==(const Vector2 & other) const {
         return (x == other.x) && (y == other.y);
    }

    // Magnitude and normalization
    float Magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2<T, U> Normalize() const {
        float magnitude = Magnitude();
        if (magnitude != 0) {
            return Vector2<T, U>(x / magnitude, y / magnitude);
        }
        else {
            return *this;
        }
    }

    // Properties
    T X() const {
        return x;
    }

    U Y() const {
        return y;
    }

    // Static properties for common vectors
    static Vector2<T, U> Up() {
        return Vector2<T, U>(0, 1);
    }

    static Vector2<T, U> Down() {
        return Vector2<T, U>(0, -1);
    }

    static Vector2<T, U> Left() {
        return Vector2<T, U>(-1, 0);
    }

    static Vector2<T, U> Right() {
        return Vector2<T, U>(1, 0);
    }

    static Vector2<T, U> One() {
        return Vector2<T, U>(1, 1);
    }

    static Vector2<T, U> Zero() {
        return Vector2<T, U>(0, 0);
    }

    static Vector2<T, U> NegativeInfinity() {
        return Vector2<T, U>(std::numeric_limits<T>::min(), std::numeric_limits<U>::min());
    }

    static Vector2<T, U> PositiveInfinity() {
        return Vector2<T, U>(std::numeric_limits<T>::max(), std::numeric_limits<U>::max());
    }
};