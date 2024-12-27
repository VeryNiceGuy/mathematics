#include "dual_quaternion.h"

struct DualQuaternion dual_quaternion_add(struct DualQuaternion a, struct DualQuaternion b) {
    return (struct DualQuaternion) {
        .real = quaternion_add(a.real, b.real),
        .dual = quaternion_add(a.dual, b.dual)
    };
}

struct DualQuaternion dual_quaternion_subtract(struct DualQuaternion a, struct DualQuaternion b) {
    return (struct DualQuaternion) {
        .real = quaternion_subtract(a.real, b.real),
        .dual = quaternion_subtract(a.dual, b.dual)
    };
}

struct DualQuaternion dual_quaternion_multiply(struct DualQuaternion a, struct DualQuaternion b) {
    return (struct DualQuaternion) {
        .real = quaternion_multiply(a.real, b.real),
        .dual = quaternion_add(quaternion_multiply(a.real, b.dual), quaternion_multiply(a.dual, b.real))
    };
}

struct DualQuaternion dual_quaternion_multiplys(struct DualQuaternion dq, float scalar) {
    return (struct DualQuaternion) {
        .real = quaternion_multiplys(dq.real, scalar),
        .dual = quaternion_multiplys(dq.dual, scalar)
    };
}

struct DualQuaternion dual_quaternion_conjugate(struct DualQuaternion dq) {
    return (struct DualQuaternion) {
        .real = quaternion_conjugate(dq.real),
        .dual = quaternion_conjugate(dq.dual)
    };
}

struct DualQuaternion dual_quaternion_normalize(struct DualQuaternion dq) {
    float mag = quaternion_magnitude(dq.real);

    return (struct DualQuaternion) {
        .real = quaternion_normalize(dq.real),
        .dual = quaternion_multiplys(dq.dual, 1.0f / mag)
    };
}
