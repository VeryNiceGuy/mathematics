#include "vector3.h"
#include <math.h>

struct vector3 vector3Normalize(struct vector3 v) {
    float length = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);

    return (struct vector3) {
        .x = v.x / length,
        .y = v.y / length,
        .z = v.z / length
    };
}

float vector3Magnitude(struct vector3 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

struct vector3 vector3Add(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = v1.x + v2.x,
        .y = v1.y + v2.y,
        .z = v1.z + v2.z
    };
}

struct vector3 vector3Adds(struct vector3 v, float s) {
    return (struct vector3) {
        .x = v.x + s,
        .y = v.y + s,
        .z = v.z + s
    };
}

struct vector3 vector3Subtract(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = v1.x - v2.x,
        .y = v1.y - v2.y,
        .z = v1.z - v2.z
    };
}

struct vector3 vector3Subtracts(struct vector3 v, float s) {
    return (struct vector3) {
        .x = v.x - s,
        .y = v.y - s,
        .z = v.z - s
    };
}

struct vector3 vector3Multiply(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = v1.x * v2.x,
        .y = v1.y * v2.y,
        .z = v1.z * v2.z
    };
}

struct vector3 vector3Multiplys(struct vector3 v, float s) {
    return (struct vector3) {
        .x = v.x * s,
        .y = v.y * s,
        .z = v.z * s
    };
}

struct vector3 vector3Divide(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = v1.x / v2.x,
        .y = v1.y / v2.y,
        .z = v1.z / v2.z
    };
}

struct vector3 vector3Divides(struct vector3 v, float s) {
    return (struct vector3) {
        .x = v.x / s,
        .y = v.y / s,
        .z = v.z / s
    };
}

struct vector3 vector3Cross(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = v1.y * v2.z - v1.z * v2.y,
        .y = v1.z * v2.x - v1.x * v2.z,
        .z = v1.x * v2.y - v1.y * v2.x
    };
}

float vector3Dot(struct vector3 v1, struct vector3 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float vector3DistanceTo(struct vector3 v1, struct vector3 v2) {
    return sqrtf(
        (v1.x - v2.x) * (v1.x - v2.x)
        + (v1.y - v2.y) * (v1.y - v2.y)
        + (v1.z - v2.z) * (v1.z - v2.z));
}

float vector3AngleBetween(struct vector3 v1, struct vector3 v2) {
    float dotProduct = vector3Dot(v1, v2);
    float magnitudes = vector3Magnitude(v1) * vector3Magnitude(v2);

    return acosf(dotProduct / magnitudes);
}

float vector3AngleTo(struct vector3 v1, struct vector3 v2) {
    return atan2f(vector3Magnitude(vector3Cross(v1, v2)), vector3Dot(v1, v2));
}

struct vector3 vector3Reflect(struct vector3 v, struct vector3 normal) {
    return vector3Subtract(v, vector3Multiplys(normal, 2 * vector3Dot(v, normal)));
}

struct vector3 vector3Lerp(struct vector3 v1, struct vector3 v2, float t) {
    return vector3Add(vector3Multiplys(v1, 1.0f - t), vector3Multiplys(v2, t));
}

struct vector3 vector3Clamp(struct vector3 v, struct vector3 min, struct vector3 max) {
    return (struct vector3) {
        .x = fmaxf(min.x, fminf(v.x, max.x)),
        .y = fmaxf(min.y, fminf(v.y, max.y)),
        .z = fmaxf(min.z, fminf(v.z, max.z))
    };
}

struct vector3 vector3Midpoint(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = (v1.x + v2.x) / 2.0f,
        .y = (v1.y + v2.y) / 2.0f,
        .z = (v1.z + v2.z) / 2.0f
    };
}

struct vector3 vector3ProjectOnto(struct vector3 v1, struct vector3 v2) {
    float dotProduct = vector3Dot(v1, v2);
    float otherMagnitudeSquared = vector3Magnitude(v2) * vector3Magnitude(v2);

    return vector3Multiplys(v2, dotProduct / otherMagnitudeSquared);
}

struct vector3 vector3PerpendicularTo(struct vector3 v1, struct vector3 v2) {
    return vector3Subtract(v1, vector3ProjectOnto(v1, v2));
}

float vector3TripleProduct(struct vector3 v, struct vector3 v1, struct vector3 v2) {
    return vector3Dot(v, vector3Cross(v1, v2));
}

struct vector3 vector3RotateAroundAxis(struct vector3 v, struct vector3 axis, float angle) {
    struct vector3 normalizedAxis = vector3Normalize(axis);
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    return vector3Add(
        vector3Add(vector3Multiplys(v, cosAngle), vector3Multiplys(vector3Cross(normalizedAxis, v), sinAngle)),
        vector3Multiplys(normalizedAxis, vector3Dot(normalizedAxis, v) * (1.0f - cosAngle))
    );
}

struct vector3 vector3RotateX(struct vector3 v, float angle) {
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    return (struct vector3) {
        .x = v.x,
        .y = v.y * cosAngle - v.z * sinAngle,
        .z = v.y * sinAngle + v.z * cosAngle
    };
}

struct vector3 vector3RotateY(struct vector3 v, float angle) {
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    return (struct vector3) {
        .x = v.x * cosAngle + v.z * sinAngle,
        .y = v.y,
        .z = -v.x * sinAngle + v.z * cosAngle
    };
}

struct vector3 vector3RotateZ(struct vector3 v, float angle) {
    float cosAngle = cosf(angle);
    float sinAngle = sinf(angle);

    return (struct vector3) {
        .x = v.x * cosAngle - v.y * sinAngle,
        .y = v.x * sinAngle + v.y * cosAngle,
        .z = v.z
    };
}

struct vector3 vector3Negate(struct vector3 v) {
    return (struct vector3) {
        .x = -v.x,
        .y = -v.y,
        .z = -v.z
    };
}

struct vector3 vector3Abs(struct vector3 v) {
    return (struct vector3) {
        .x = fabsf(v.x),
        .y = fabsf(v.y),
        .z = fabsf(v.z)
    };
}

float vector3MaxComponent(struct vector3 v) {
    return fmaxf(fmaxf(v.x, v.y), v.z);
}

float vector3MinComponent(struct vector3 v) {
    return fminf(fminf(v.x, v.y), v.z);
}

struct vector3 vector3Pow(struct vector3 v, float exponent) {
    return (struct vector3) {
        .x = powf(v.x, exponent),
        .y = powf(v.y, exponent),
        .z = powf(v.z, exponent)
    };
}

struct vector3 vector3Sqrt(struct vector3 v) {
    return (struct vector3) {
        .x = sqrtf(v.x),
        .y = sqrtf(v.y),
        .z = sqrtf(v.z)
    };
}

struct vector3 vector3Min(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = fminf(v1.x, v2.x),
        .y = fminf(v1.y, v2.y),
        .z = fminf(v1.z, v2.z)
    };
}

struct vector3 vector3Max(struct vector3 v1, struct vector3 v2) {
    return (struct vector3) {
        .x = fmaxf(v1.x, v2.x),
        .y = fmaxf(v1.y, v2.y),
        .z = fmaxf(v1.z, v2.z)
    };
}

struct vector3 vector3Round(struct vector3 v) {
    return (struct vector3) {
        .x = roundf(v.x),
        .y = roundf(v.y),
        .z = roundf(v.z)
    };
}

struct vector3 vector3Floor(struct vector3 v) {
    return (struct vector3) {
        .x = floorf(v.x),
        .y = floorf(v.y),
        .z = floorf(v.z)
    };
}

struct vector3 vector3Ceil(struct vector3 v) {
    return (struct vector3) {
        .x = ceilf(v.x),
        .y = ceilf(v.y),
        .z = ceilf(v.z)
    };
}

struct vector3 vector3Log(struct vector3 v) {
    return (struct vector3) {
        .x = logf(v.x),
        .y = logf(v.y),
        .z = logf(v.z)
    };
}

struct vector3 vector3Exp(struct vector3 v) {
    return (struct vector3) {
        .x = expf(v.x),
        .y = expf(v.y),
        .z = expf(v.z)
    };
}