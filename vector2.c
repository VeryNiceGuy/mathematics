#include "vector2.h"

struct Vector2 vector2_normalize(struct Vector2 v) {
    float length = sqrtf(v.x * v.x + v.y * v.y);

    return (struct Vector2) {
        .x = v.x / length,
        .y = v.y / length
    };
}

float vector2_magnitude(struct Vector2 v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

struct Vector2 vector2_add(struct Vector2 v1, struct Vector2 v2) {
    return (struct Vector2) {
        .x = v1.x + v2.x,
        .y = v1.y + v2.y
    };
}

struct Vector2 vector2_adds(struct Vector2 v, float s) {
    return (struct Vector2) {
        .x = v.x + s,
        .y = v.y + s
    };
}

struct Vector2 vector2_subtract(struct Vector2 v1, struct Vector2 v2) {
    return (struct Vector2) {
        .x = v1.x - v2.x,
        .y = v1.y - v2.y
    };
}

struct Vector2 vector2_subtracts(struct Vector2 v, float s) {
    return (struct Vector2) {
        .x = v.x - s,
        .y = v.y - s
    };
}

struct Vector2 vector2_multiply(struct Vector2 v1, struct Vector2 v2) {
    return (struct Vector2) {
        .x = v1.x * v2.x,
        .y = v1.y * v2.y
    };
}

struct Vector2 vector2_multiplys(struct Vector2 v, float s) {
    return (struct Vector2) {
        .x = v.x * s,
        .y = v.y * s
    };
}

struct Vector2 vector2_divide(struct Vector2 v1, struct Vector2 v2) {
    return (struct Vector2) {
        .x = v1.x / v2.x,
        .y = v1.y / v2.y
    };
}

struct Vector2 vector2_divides(struct Vector2 v, float s) {
    return (struct Vector2) {
        .x = v.x / s,
        .y = v.y / s
    };
}

float vector2_cross(struct Vector2 a, struct Vector2 b) {
    return a.x * b.y - a.y * b.x;
}

float vector2_dot(struct Vector2 v1, struct Vector2 v2) {
    return v1.x * v2.x + v1.y * v2.y;
}