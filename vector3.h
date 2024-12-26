#pragma once

struct vector3 {
    float x, y, z;
};

struct vector3 normalize(struct vector3 v);
float magnitude(struct vector3 v);
struct vector3 add(struct vector3 v1, struct vector3 v2);
struct vector3 adds(struct vector3 v, float s);
struct vector3 subtract(struct vector3 v1, struct vector3 v2);
struct vector3 subtracts(struct vector3 v, float s);
struct vector3 multiply(struct vector3 v1, struct vector3 v2);
struct vector3 multiplys(struct vector3 v, float s);
struct vector3 divide(struct vector3 v1, struct vector3 v2);
struct vector3 divides(struct vector3 v, float s);
struct vector3 cross(struct vector3 v1, struct vector3 v2);
float dot(struct vector3 v1, struct vector3 v2);
float distanceTo(struct vector3 v1, struct vector3 v2);
float angleBetween(struct vector3 v1, struct vector3 v2);
float angleTo(struct vector3 v1, struct vector3 v2);
struct vector3 reflect(struct vector3 v, struct vector3 normal);
struct vector3 lerp(struct vector3 v1, struct vector3 v2, float t);
struct vector3 clamp(struct vector3 v, struct vector3 min, struct vector3 max);
struct vector3 midpoint(struct vector3 v1, struct vector3 v2);
struct vector3 projectOnto(struct vector3 v1, struct vector3 v2);
struct vector3 perpendicularTo(struct vector3 v1, struct vector3 v2);
float tripleProduct(struct vector3 v, struct vector3 v1, struct vector3 v2);
struct vector3 rotateAroundAxis(struct vector3 v, struct vector3 axis, float angle);
struct vector3 rotateX(struct vector3 v, float angle);
struct vector3 rotateY(struct vector3 v, float angle);
struct vector3 rotateZ(struct vector3 v, float angle);
struct vector3 negate(struct vector3 v);
struct vector3 absv(struct vector3 v);
float maxComponent(struct vector3 v);
float minComponent(struct vector3 v);
struct vector3 powv(struct vector3 v, float exponent);
struct vector3 sqrtv(struct vector3 v);
struct vector3 minv(struct vector3 v1, struct vector3 v2);
struct vector3 maxv(struct vector3 v1, struct vector3 v2);
struct vector3 roundv(struct vector3 v);
struct vector3 floorv(struct vector3 v);
struct vector3 ceilv(struct vector3 v);
struct vector3 logv(struct vector3 v);
struct vector3 expv(struct vector3 v);