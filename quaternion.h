#pragma once

struct quaternion {
    float w, x, y, z;
};

struct quaternion quaternionAdd(struct quaternion a, struct quaternion b);
struct quaternion quaternionSubtract(struct quaternion a, struct quaternion b);
struct quaternion quaternionMultiply(struct quaternion a, struct quaternion b);
struct quaternion quaternionMultiplys(struct quaternion q, float s);
float quaternionMagnitude(struct quaternion q);
struct quaternion quaternionNormalize(struct quaternion q);
struct quaternion quaternionConjugate(struct quaternion q);
struct quaternion quaternionInverse(struct quaternion q);