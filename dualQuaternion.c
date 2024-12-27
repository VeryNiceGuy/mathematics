#include "dualQuaternion.h"

struct dualQuaternion dualQuaternionAdd(struct dualQuaternion a, struct dualQuaternion b) {
    return (struct dualQuaternion) {
        .real = quaternionAdd(a.real, b.real),
        .dual = quaternionAdd(a.dual, b.dual)
    };
}

struct dualQuaternion dualQuaternionSubtract(struct dualQuaternion a, struct dualQuaternion b) {
    return (struct dualQuaternion) {
        .real = quaternionSubtract(a.real, b.real),
        .dual = quaternionSubtract(a.dual, b.dual)
    };
}

struct dualQuaternion dualQuaternionMultiply(struct dualQuaternion a, struct dualQuaternion b) {
    return (struct dualQuaternion) {
        .real = quaternionMultiply(a.real, b.real),
        .dual = quaternionAdd(quaternionMultiply(a.real, b.dual), quaternionMultiply(a.dual, b.real))
    };
}

struct dualQuaternion dualQuaternionMultiplys(struct dualQuaternion dq, float scalar) {
    return (struct dualQuaternion) {
        .real = quaternionMultiplys(dq.real, scalar),
        .dual = quaternionMultiplys(dq.dual, scalar)
    };
}

struct dualQuaternion dualQuaternionConjugate(struct dualQuaternion dq) {
    return (struct dualQuaternion) {
        .real = quaternionConjugate(dq.real),
        .dual = quaternionConjugate(dq.dual)
    };
}

struct dualQuaternion dualQuaternionNormalize(struct dualQuaternion dq) {
    float mag = quaternionMagnitude(dq.real);

    return (struct dualQuaternion) {
        .real = quaternionNormalize(dq.real),
        .dual = quaternionMultiplys(dq.dual, 1.0f / mag)
    };
}
