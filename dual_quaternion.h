#pragma once
#include "quaternion.h"

struct DualQuaternion {
    struct Quaternion real;
    struct Quaternion dual;
};

struct DualQuaternion dual_quaternion_add(struct DualQuaternion a, struct DualQuaternion b);
struct DualQuaternion dual_quaternion_subtract(struct DualQuaternion a, struct DualQuaternion b);
struct DualQuaternion dual_quaternion_multiply(struct DualQuaternion a, struct DualQuaternion b);
struct DualQuaternion dual_quaternion_multiply_scalar(struct DualQuaternion dq, float scalar);
struct DualQuaternion dual_quaternion_conjugate(struct DualQuaternion dq);
struct DualQuaternion dual_quaternion_normalize(struct DualQuaternion dq);
