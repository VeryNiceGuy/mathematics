#include "vector3.h"
#include <math.h>

struct Vector3 vector3_normalize(struct Vector3 v) {
    float length = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);

    return (struct Vector3) {
        .x = v.x / length,
        .y = v.y / length,
        .z = v.z / length
    };
}

float vector3_magnitude(struct Vector3 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

struct Vector3 vector3_add(struct Vector3 v1, struct Vector3 v2) {
    return (struct Vector3) {
        .x = v1.x + v2.x,
        .y = v1.y + v2.y,
        .z = v1.z + v2.z
    };
}

struct Vector3 vector3_adds(struct Vector3 v, float s) {
    return (struct Vector3) {
        .x = v.x + s,
        .y = v.y + s,
        .z = v.z + s
    };
}

struct Vector3 vector3_subtract(struct Vector3 v1, struct Vector3 v2) {
    return (struct Vector3) {
        .x = v1.x - v2.x,
        .y = v1.y - v2.y,
        .z = v1.z - v2.z
    };
}

struct Vector3 vector3_subtracts(struct Vector3 v, float s) {
    return (struct Vector3) {
        .x = v.x - s,
        .y = v.y - s,
        .z = v.z - s
    };
}

struct Vector3 vector3_multiply(struct Vector3 v1, struct Vector3 v2) {
    return (struct Vector3) {
        .x = v1.x * v2.x,
        .y = v1.y * v2.y,
        .z = v1.z * v2.z
    };
}

struct Vector3 vector3_multiplys(struct Vector3 v, float s) {
    return (struct Vector3) {
        .x = v.x * s,
        .y = v.y * s,
        .z = v.z * s
    };
}

struct Vector3 vector3_divide(struct Vector3 v1, struct Vector3 v2) {
    return (struct Vector3) {
        .x = v1.x / v2.x,
        .y = v1.y / v2.y,
        .z = v1.z / v2.z
    };
}

struct Vector3 vector3_divides(struct Vector3 v, float s) {
    return (struct Vector3) {
        .x = v.x / s,
        .y = v.y / s,
        .z = v.z / s
    };
}

struct Vector3 vector3_cross(struct Vector3 v1, struct Vector3 v2) {
    return (struct Vector3) {
        .x = v1.y * v2.z - v1.z * v2.y,
        .y = v1.z * v2.x - v1.x * v2.z,
        .z = v1.x * v2.y - v1.y * v2.x
    };
}

float vector3_dot(struct Vector3 v1, struct Vector3 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float vector3_distance_to(struct Vector3 v1, struct Vector3 v2) {
    return sqrtf(
        (v1.x - v2.x) * (v1.x - v2.x)
        + (v1.y - v2.y) * (v1.y - v2.y)
        + (v1.z - v2.z) * (v1.z - v2.z));
}

float vector3_angle_between(struct Vector3 v1, struct Vector3 v2) {
    float dotProduct = vector3_dot(v1, v2);
    float magnitudes = vector3_magnitude(v1) * vector3_magnitude(v2);

    return acosf(dotProduct / magnitudes);
}

float vector3_angle_to(struct Vector3 v1, struct Vector3 v2) {
    return atan2f(vector3_magnitude(vector3_cross(v1, v2)), vector3_dot(v1, v2));
}

struct Vector3 vector3_reflect(struct Vector3 v, struct Vector3 normal) {
    return vector3_subtract(v, vector3_multiplys(normal, 2 * vector3_dot(v, normal)));
}

struct Vector3 vector3_lerp(struct Vector3 v1, struct Vector3 v2, float t) {
    return vector3_add(vector3_multiplys(v1, 1.0f - t), vector3_multiplys(v2, t));
}

struct Vector3 vector3_clamp(struct Vector3 v, struct Vector3 min, struct Vector3 max) {
    return (struct Vector3) {
        .x = fmaxf(min.x, fminf(v.x, max.x)),
        .y = fmaxf(min.y, fminf(v.y, max.y)),
        .z = fmaxf(min.z, fminf(v.z, max.z))
    };
}

struct Vector3 vector3_midpoint(struct Vector3 v1, struct Vector3 v2) {
    return (struct Vector3) {
        .x = (v1.x + v2.x) / 2.0f,
        .y = (v1.y + v2.y) / 2.0f,
        .z = (v1.z + v2.z) / 2.0f
    };
}

struct Vector3 vector3_project_onto(struct Vector3 v1, struct Vector3 v2) {
    float dotProduct = vector3_dot(v1, v2);
    float otherMagnitudeSquared = vector3_magnitude(v2) * vector3_magnitude(v2);

    return vector3_multiplys(v2, dotProduct / otherMagnitudeSquared);
}

struct Vector3 vector3_perpendicular_to(struct Vector3 v1, struct Vector3 v2) {
    return vector3_subtract(v1, vector3_project_onto(v1, v2));
}

float vector3_triple_product(struct Vector3 v, struct Vector3 v1, struct Vector3 v2) {
    return vector3_dot(v, vector3_cross(v1, v2));
}

struct Vector3 vector3_rotate_around_axis(struct Vector3 v, struct Vector3 axis, float angle) {
    struct Vector3 normalizedAxis = vector3_normalize(axis);
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    return vector3_add(
        vector3_add(vector3_multiplys(v, cosAngle), vector3_multiplys(vector3_cross(normalizedAxis, v), sinAngle)),
        vector3_multiplys(normalizedAxis, vector3_dot(normalizedAxis, v) * (1.0f - cosAngle))
    );
}

struct Vector3 vector3_rotate_x(struct Vector3 v, float angle) {
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    return (struct Vector3) {
        .x = v.x,
        .y = v.y * cosAngle - v.z * sinAngle,
        .z = v.y * sinAngle + v.z * cosAngle
    };
}

struct Vector3 vector3_rotate_y(struct Vector3 v, float angle) {
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    return (struct Vector3) {
        .x = v.x * cosAngle + v.z * sinAngle,
        .y = v.y,
        .z = -v.x * sinAngle + v.z * cosAngle
    };
}

struct Vector3 vector3_rotate_z(struct Vector3 v, float angle) {
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    return (struct Vector3) {
        .x = v.x * cosAngle - v.y * sinAngle,
        .y = v.x * sinAngle + v.y * cosAngle,
        .z = v.z
    };
}

struct Vector3 vector3_negate(struct Vector3 v) {
    return (struct Vector3) {
        .x = -v.x,
        .y = -v.y,
        .z = -v.z
    };
}

struct Vector3 vector3_abs(struct Vector3 v) {
    return (struct Vector3) {
        .x = fabsf(v.x),
        .y = fabsf(v.y),
        .z = fabsf(v.z)
    };
}

float vector3_max_component(struct Vector3 v) {
    return fmaxf(fmaxf(v.x, v.y), v.z);
}

float vector3_min_component(struct Vector3 v) {
    return fminf(fminf(v.x, v.y), v.z);
}

struct Vector3 vector3_pow(struct Vector3 v, float exponent) {
    return (struct Vector3) {
        .x = powf(v.x, exponent),
        .y = powf(v.y, exponent),
        .z = powf(v.z, exponent)
    };
}

struct Vector3 vector3_sqrt(struct Vector3 v) {
    return (struct Vector3) {
        .x = sqrtf(v.x),
        .y = sqrtf(v.y),
        .z = sqrtf(v.z)
    };
}

struct Vector3 vector3_min(struct Vector3 v1, struct Vector3 v2) {
    return (struct Vector3) {
        .x = fminf(v1.x, v2.x),
        .y = fminf(v1.y, v2.y),
        .z = fminf(v1.z, v2.z)
    };
}

struct Vector3 vector3_max(struct Vector3 v1, struct Vector3 v2) {
    return (struct Vector3) {
        .x = fmaxf(v1.x, v2.x),
        .y = fmaxf(v1.y, v2.y),
        .z = fmaxf(v1.z, v2.z)
    };
}

struct Vector3 vector3_round(struct Vector3 v) {
    return (struct Vector3) {
        .x = roundf(v.x),
        .y = roundf(v.y),
        .z = roundf(v.z)
    };
}

struct Vector3 vector3_floor(struct Vector3 v) {
    return (struct Vector3) {
        .x = floorf(v.x),
        .y = floorf(v.y),
        .z = floorf(v.z)
    };
}

struct Vector3 vector3_ceil(struct Vector3 v) {
    return (struct Vector3) {
        .x = ceilf(v.x),
        .y = ceilf(v.y),
        .z = ceilf(v.z)
    };
}

struct Vector3 vector3_log(struct Vector3 v) {
    return (struct Vector3) {
        .x = logf(v.x),
        .y = logf(v.y),
        .z = logf(v.z)
    };
}

struct Vector3 vector3_exp(struct Vector3 v) {
    return (struct Vector3) {
        .x = expf(v.x),
        .y = expf(v.y),
        .z = expf(v.z)
    };
}