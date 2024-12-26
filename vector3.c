#include "vector3.h"
#include <math.h>

struct vector3 normalize(struct vector3 v) {
    float length = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);

    return (struct vector3) {
        .x = v.x / length,
        .y = v.y / length,
        .z = v.z / length
    };
}

float magnitude(struct vector3 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

struct vector3 add(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = v1.x + v2.x,
        .y = v1.y + v2.y,
        .z = v1.z + v2.z
    };
}

struct vector3 adds(struct vector3 v, float s) {
    return (struct vector3) {
        .x = v.x + s,
        .y = v.y + s,
        .z = v.z + s
    };
}

struct vector3 subtract(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = v1.x - v2.x,
        .y = v1.y - v2.y,
        .z = v1.z - v2.z
    };
}

struct vector3 subtracts(struct vector3 v, float s) {
    return (struct vector3) {
        .x = v.x - s,
        .y = v.y - s,
        .z = v.z - s
    };
}

struct vector3 multiply(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = v1.x * v2.x,
        .y = v1.y * v2.y,
        .z = v1.z * v2.z
    };
}

struct vector3 multiplys(struct vector3 v, float s) {
    return (struct vector3) {
        .x = v.x * s,
        .y = v.y * s,
        .z = v.z * s
    };
}

struct vector3 divide(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = v1.x / v2.x,
        .y = v1.y / v2.y,
        .z = v1.z / v2.z
    };
}

struct vector3 divides(struct vector3 v, float s) {
    return (struct vector3) {
        .x = v.x / s,
        .y = v.y / s,
        .z = v.z / s
    };
}

struct vector3 cross(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = v1.y * v2.z - v1.z * v2.y,
        .y = v1.z * v2.x - v1.x * v2.z,
        .z = v1.x * v2.y - v1.y * v2.x
    };
}

float dot(struct vector3 v1, struct vector3 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float distanceTo(struct vector3 v1, struct vector3 v2) {
    return sqrtf(
        (v1.x - v2.x) * (v1.x - v2.x)
        + (v1.y - v2.y) * (v1.y - v2.y)
        + (v1.z - v2.z) * (v1.z - v2.z));
}

float angleBetween(struct vector3 v1, struct vector3 v2) {
    float dotProduct = dot(v1, v2);
    float magnitudes = magnitude(v1) * magnitude(v2);

    return acosf(dotProduct / magnitudes);
}

float angleTo(struct vector3 v1, struct vector3 v2) {
    return atan2f(magnitude(cross(v1, v2)), dot(v1, v2));
}

struct vector3 reflect(struct vector3 v, struct vector3 normal) {
    return subtract(v, multiplys(normal, 2 * dot(v, normal)));
}

struct vector3 lerp(struct vector3 v1, struct vector3 v2, float t) {
    return add(multiplys(v1, 1.0f - t), multiplys(v2, t));
}

struct vector3 clamp(struct vector3 v, struct vector3 min, struct vector3 max) {
    return (struct vector3) {
        .x = fmaxf(min.x, fminf(v.x, max.x)),
        .y = fmaxf(min.y, fminf(v.y, max.y)),
        .z = fmaxf(min.z, fminf(v.z, max.z))
    };
}

struct vector3 midpoint(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = (v1.x + v2.x) / 2.0f,
        .y = (v1.y + v2.y) / 2.0f,
        .z = (v1.z + v2.z) / 2.0f
    };
}

struct vector3 projectOnto(struct vector3 v1, struct vector3 v2) {
    float dotProduct = dot(v1, v2);
    float otherMagnitudeSquared = magnitude(v2) * magnitude(v2);

    return multiplys(v2, dotProduct / otherMagnitudeSquared);
}

struct vector3 perpendicularTo(struct vector3 v1, struct vector3 v2) {
    return subtract(v1, projectOnto(v1, v2));
}

float tripleProduct(struct vector3 v, struct vector3 v1, struct vector3 v2) {
    return dot(v, cross(v1, v2));
}

struct vector3 rotateAroundAxis(struct vector3 v, struct vector3 axis, float angle) {
    struct vector3 normalizedAxis = normalize(axis);
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    return add(
        add(multiplys(v, cosAngle), multiplys(cross(normalizedAxis, v), sinAngle)),
        multiplys(normalizedAxis, dot(normalizedAxis, v) * (1.0f - cosAngle))
    );
}

struct vector3 rotateX(struct vector3 v, float angle) {
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    return (struct vector3) {
        .x = v.x,
        .y = v.y * cosAngle - v.z * sinAngle,
        .z = v.y * sinAngle + v.z * cosAngle
    };
}

struct vector3 rotateY(struct vector3 v, float angle) {
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    return (struct vector3) {
        .x = v.x * cosAngle + v.z * sinAngle,
        .y = v.y,
        .z = -v.x * sinAngle + v.z * cosAngle
    };
}

struct vector3 rotateZ(struct vector3 v, float angle) {
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    return (struct vector3) {
        .x = v.x * cosAngle - v.y * sinAngle,
        .y = v.x * sinAngle + v.y * cosAngle,
        .z = v.z
    };
}

struct vector3 negate(struct vector3 v) {
    return (struct vector3) {
        .x = -v.x,
        .y = -v.y,
        .z = -v.z
    };
}

struct vector3 absv(struct vector3 v) {
    return (struct vector3) {
        .x = fabsf(v.x),
        .y = fabsf(v.y),
        .z = fabsf(v.z)
    };
}

float maxComponent(struct vector3 v) {
    return fmaxf(fmaxf(v.x, v.y), v.z);
}

float minComponent(struct vector3 v) {
    return fminf(fminf(v.x, v.y), v.z);
}

struct vector3 powv(struct vector3 v, float exponent) {
    return (struct vector3) {
        .x = powf(v.x, exponent),
        .y = powf(v.y, exponent),
        .z = powf(v.z, exponent)
    };
}

struct vector3 sqrtv(struct vector3 v) {
    return (struct vector3) {
        .x = sqrtf(v.x),
        .y = sqrtf(v.y),
        .z = sqrtf(v.z)
    };
}

struct vector3 minv(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = fminf(v1.x, v2.x),
        .y = fminf(v1.y, v2.y),
        .z = fminf(v1.z, v2.z)
    };
}

struct vector3 maxv(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = fmaxf(v1.x, v2.x),
        .y = fmaxf(v1.y, v2.y),
        .z = fmaxf(v1.z, v2.z)
    };
}

struct vector3 roundv(struct vector3 v) {
    return (struct vector3) {
        .x = roundf(v.x),
        .y = roundf(v.y),
        .z = roundf(v.z)
    };
}

struct vector3 floorv(struct vector3 v) {
    return (struct vector3) {
        .x = floorf(v.x),
        .y = floorf(v.y),
        .z = floorf(v.z)
    };
}

struct vector3 ceilv(struct vector3 v) {
    return (struct vector3) {
        .x = ceilf(v.x),
        .y = ceilf(v.y),
        .z = ceilf(v.z)
    };
}

struct vector3 logv(struct vector3 v) {
    return (struct vector3) {
        .x = logf(v.x),
        .y = logf(v.y),
        .z = logf(v.z)
    };
}

struct vector3 expv(struct vector3 v) {
    return (struct vector3) {
        .x = expf(v.x),
        .y = expf(v.y),
        .z = expf(v.z)
    };
}