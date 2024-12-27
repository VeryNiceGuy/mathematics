#include "quaternion.h"
#include <math.h>

struct Quaternion quaternion_add(struct Quaternion a, struct Quaternion b) {
    return (struct Quaternion) {
        .w = a.w + b.w,
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z
    };
}

struct Quaternion quaternion_subtract(struct Quaternion a, struct Quaternion b) {
    return (struct Quaternion) {
        .w = a.w - b.w,
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z
    };
}

struct Quaternion quaternion_multiply(struct Quaternion a, struct Quaternion b) {
    return (struct Quaternion) {
        .w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
        .x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
        .y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
        .z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w
    };
}

struct Quaternion quaternion_multiplys(struct Quaternion q, float scalar) {
    return (struct Quaternion) {
        .w = q.w * scalar,
        .x = q.x * scalar,
        .y = q.y * scalar,
        .z = q.z * scalar
    };
}

float quaternion_magnitude(struct Quaternion q) {
    return sqrtf(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
}

struct Quaternion quaternion_normalize(struct Quaternion q) {
    float mag = quaternion_magnitude(q);

    return (struct Quaternion) {
        .w = q.w / mag,
        .x = q.x / mag,
        .y = q.y / mag,
        .z = q.z / mag };
}

struct Quaternion quaternion_conjugate(struct Quaternion q) {
    return (struct Quaternion) {
        .w = q.w,
        .x = -q.x,
        .y = -q.y,
        .z = -q.z
    };
}

struct Quaternion quaternion_inverse(struct Quaternion q) {
    struct Quaternion conjugated = quaternion_conjugate(q);
    float magSquared = quaternion_magnitude(q) * quaternion_magnitude(q);

    return (struct Quaternion) {
        .w = conjugated.w / magSquared,
        .x = conjugated.x / magSquared,
        .y = conjugated.y / magSquared,
        .z = conjugated.z / magSquared
    };
}
