#include "quaternion.h"
#include <math.h>

struct quaternion quaternionAdd(struct quaternion a, struct quaternion b) {
    return (struct quaternion) {
        .w = a.w + b.w,
        .x = a.x + b.x,
        .y = a.y + b.y,
        .z = a.z + b.z
    };
}

struct quaternion quaternionSubtract(struct quaternion a, struct quaternion b) {
    return (struct quaternion) {
        .w = a.w - b.w,
        .x = a.x - b.x,
        .y = a.y - b.y,
        .z = a.z - b.z
    };
}

struct quaternion quaternionMultiply(struct quaternion a, struct quaternion b) {
    return (struct quaternion) {
        .w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
        .x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
        .y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
        .z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w
    };
}

struct quaternion quaternionMultiplys(struct quaternion q, float scalar) {
    return (struct quaternion) {
        .w = q.w * scalar,
        .x = q.x * scalar,
        .y = q.y * scalar,
        .z = q.z * scalar
    };
}

float quaternionMagnitude(struct quaternion q) {
    return sqrtf(q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);
}

struct quaternion quaternionNormalize(struct quaternion q) {
    float mag = quaternionMagnitude(q);

    return (struct quaternion) {
        .w = q.w / mag,
        .x = q.x / mag,
        .y = q.y / mag,
        .z = q.z / mag };
}

struct quaternion quaternionConjugate(struct quaternion q) {
    return (struct quaternion) {
        .w = q.w,
        .x = -q.x,
        .y = -q.y,
        .z = -q.z
    };
}

struct quaternion quaternionInverse(struct quaternion q) {
    struct quaternion conjugated = quaternionConjugate(q);
    float magSquared = quaternionMagnitude(q) * quaternionMagnitude(q);

    return (struct quaternion) {
        .w = conjugated.w / magSquared,
        .x = conjugated.x / magSquared,
        .y = conjugated.y / magSquared,
        .z = conjugated.z / magSquared
    };
}
