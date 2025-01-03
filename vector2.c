#include "vector2.h"
#include <math.h>

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

float vector2_distance_to(struct Vector2 a, struct Vector2 b) {
    return sqrtf((a.x - b.x) * (a.x - b.x) +
        (a.y - b.y) * (a.y - b.y));
}

struct Vector2 vector2_rotate(struct Vector2 v, float angle) {
    return (struct Vector2) {
        .x = v.x * cosf(angle) - v.y * sinf(angle),
        .y = v.x * sinf(angle) + v.y * cosf(angle)
    };
}

struct Vector2 vector2_negate(struct Vector2 v) {
    return (struct Vector2) {
        .x = -v.x,
        .y = -v.y,
    };
}

struct Vector2 vector2_abs(struct Vector2 v) {
    return (struct Vector2) {
        .x = fabsf(v.x),
        .y = fabsf(v.y)
    };
}

float vector2_max_component(struct Vector2 v) {
    return fmaxf(v.x, v.y);
}

float vector2_min_component(struct Vector2 v) {
    return fminf(v.x, v.y);
}

struct Vector2 vector2_pow(struct Vector2 v, float exponent) {
    return (struct Vector2) {
        .x = powf(v.x, exponent),
        .y = powf(v.y, exponent)
    };
}

struct Vector2 vector2_sqrt(struct Vector2 v) {
    return (struct Vector2) {
        .x = sqrtf(v.x),
        .y = sqrtf(v.y)
    };
}

struct Vector2 vector2_min(struct Vector2 v1, struct Vector2 v2) {
    return (struct Vector2) {
        .x = fminf(v1.x, v2.x),
        .y = fminf(v1.y, v2.y)
    };
}

struct Vector2 vector3_max(struct Vector2 v1, struct Vector2 v2) {
    return (struct Vector2) {
        .x = fmaxf(v1.x, v2.x),
        .y = fmaxf(v1.y, v2.y)
    };
}

struct Vector2 vector2_round(struct Vector2 v) {
    return (struct Vector2) {
        .x = roundf(v.x),
        .y = roundf(v.y)
    };
}

struct Vector2 vector2_floor(struct Vector2 v) {
    return (struct Vector2) {
        .x = floorf(v.x),
        .y = floorf(v.y)
    };
}

struct Vector2 vector2_ceil(struct Vector2 v) {
    return (struct Vector2) {
        .x = ceilf(v.x),
        .y = ceilf(v.y)
    };
}

struct Vector2 vector2_log(struct Vector2 v) {
    return (struct Vector2) {
        .x = logf(v.x),
        .y = logf(v.y)
    };
}

struct Vector2 vector2_exp(struct Vector2 v) {
    return (struct Vector2) {
        .x = expf(v.x),
        .y = expf(v.y)
    };
}