#ifndef ALGOVIZADVENTURE_VECTOR2_HPP
#define ALGOVIZADVENTURE_VECTOR2_HPP


#include <cmath>
#include <ostream>
#include "utils.cpp"

class Vector2 {
    float m_x, m_y;

public:
    Vector2(float x, float y) {m_x = x;m_y = y;}
    Vector2() {m_x = 0; m_y = 0;}

    static Vector2 zero() {return {0, 0};}
    static Vector2 one() {return {1, 1};}
    static Vector2 up() {return {0, -1};}
    static Vector2 down() {return {0, 1};}
    static Vector2 left() {return {-1, 0};}
    static Vector2 right() {return {1, 0};}
    static Vector2 random(float min=0, float max=1) {return {randomFloat(min, max), randomFloat(min, max)};}

    float x() const {return m_x;}
    float y() const {return m_y;}

    void x(float x) {m_x = x;}
    void y(float y) {m_y = y;}
    void set(float x, float y) {m_x = x; m_y = y;}

    Vector2 normalized() const {
        float length = magnitude();
        return {m_x / length, m_y/length};
    }

    float magnitude() const {
        return (float) sqrt(pow(m_x, 2) + pow(m_y, 2));
    }

    float dotProd(const Vector2& other) const {
        return m_x * other.x() + m_y * other.y();
    }


    // Vector2 with Vector2 operators
    bool operator<(const Vector2 &rhs) const {return magnitude() < rhs.magnitude();}
    bool operator>(const Vector2 &rhs) const {return magnitude() > rhs.magnitude();}
    bool operator<=(const Vector2 &rhs) const {return magnitude() <= rhs.magnitude();}
    bool operator>=(const Vector2 &rhs) const {return magnitude() >= rhs.magnitude();}

    bool operator==(const Vector2 &rhs) const {return m_x == rhs.m_x && m_y == rhs.m_y;}
    bool operator!=(const Vector2 &rhs) const {return !(rhs == *this);}

    Vector2 operator+(const Vector2& rhs) const {return {m_x + rhs.x(), m_y + rhs.y()};}
    Vector2 operator-(const Vector2& rhs) const {return {m_x - rhs.x(), m_y - rhs.y()};}
    Vector2 operator*(const Vector2& rhs) const {return {m_x * rhs.x(), m_y * rhs.y()};}
    Vector2 operator/(const Vector2& rhs) const {return {m_x / rhs.x(), m_y / rhs.y()};}

    Vector2 operator+=(const Vector2& rhs) {m_x += rhs.x(); m_y += rhs.y(); return *this;}
    Vector2 operator-=(const Vector2& rhs) {m_x -= rhs.x(); m_y -= rhs.y(); return *this;}
    Vector2 operator*=(const Vector2& rhs) {m_x *= rhs.x(); m_y *= rhs.y(); return *this;}
    Vector2 operator/=(const Vector2& rhs) {m_x /= rhs.x(); m_y /= rhs.y(); return *this;}

    // Vector2 with float operators
    Vector2 operator*(const float rhs) const {return {m_x * rhs, m_y * rhs};}
    Vector2 operator/(const float rhs) const {return {m_x / rhs, m_y / rhs};}

    Vector2 operator*=(const float rhs) {m_x *= rhs; m_y *= rhs; return *this;}
    Vector2 operator/=(const float rhs) {m_x /= rhs; m_y /= rhs; return *this;}

};

std::ostream& operator<<(std::ostream& stream, const Vector2& vec) {
    stream << "(" << vec.x() << ", " << vec.y() << ")";
    return stream;
}

#endif // ALGOVIZADVENTURE_VECTOR2_HPP