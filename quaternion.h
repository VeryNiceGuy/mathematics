#pragma once

struct Quaternion {
    float w, x, y, z;
};

struct Quaternion quaternion_add(struct Quaternion a, struct Quaternion b);
struct Quaternion quaternion_subtract(struct Quaternion a, struct Quaternion b);
struct Quaternion quaternion_multiply(struct Quaternion a, struct Quaternion b);
struct Quaternion quaternion_multiplys(struct Quaternion q, float s);
float quaternion_magnitude(struct Quaternion q);
struct Quaternion quaternion_normalize(struct Quaternion q);
struct Quaternion quaternion_conjugate(struct Quaternion q);
struct Quaternion quaternion_inverse(struct Quaternion q);