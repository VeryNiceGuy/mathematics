#pragma once
#include "quaternion.h"

struct dualQuaternion {
    struct quaternion real;
    struct quaternion dual;
};

struct dualQuaternion dualQuaternionAdd(struct dualQuaternion a, struct dualQuaternion b);
struct dualQuaternion dualQuaternionSubtract(struct dualQuaternion a, struct dualQuaternion b);
struct dualQuaternion dualQuaternionMultiply(struct dualQuaternion a, struct dualQuaternion b);
struct dualQuaternion dualQuaternionMultiplys(struct dualQuaternion dq, float scalar);
struct dualQuaternion dualQuaternionConjugate(struct dualQuaternion dq);
struct dualQuaternion dualQuaternionNormalize(struct dualQuaternion dq);