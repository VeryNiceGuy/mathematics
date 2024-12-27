#pragma once

struct vector3 {
    float x, y, z;
};

struct vector3 vector3Normalize(struct vector3 v);
float vector3Magnitude(struct vector3 v);
struct vector3 vector3Add(struct vector3 v1, struct vector3 v2);
struct vector3 vector3Adds(struct vector3 v, float s);
struct vector3 vector3Subtract(struct vector3 v1, struct vector3 v2);
struct vector3 vector3Subtracts(struct vector3 v, float s);
struct vector3 vector3Multiply(struct vector3 v1, struct vector3 v2);
struct vector3 vector3Multiplys(struct vector3 v, float s);
struct vector3 vector3Divide(struct vector3 v1, struct vector3 v2);
struct vector3 vector3Divides(struct vector3 v, float s);
struct vector3 vector3Cross(struct vector3 v1, struct vector3 v2);
float vector3Dot(struct vector3 v1, struct vector3 v2);
float vector3DistanceTo(struct vector3 v1, struct vector3 v2);
float vector3AngleBetween(struct vector3 v1, struct vector3 v2);
float vector3AngleTo(struct vector3 v1, struct vector3 v2);
struct vector3 vector3Reflect(struct vector3 v, struct vector3 normal);
struct vector3 vector3Lerp(struct vector3 v1, struct vector3 v2, float t);
struct vector3 vector3Clamp(struct vector3 v, struct vector3 min, struct vector3 max);
struct vector3 vector3Midpoint(struct vector3 v1, struct vector3 v2);
struct vector3 vector3ProjectOnto(struct vector3 v1, struct vector3 v2);
struct vector3 vector3PerpendicularTo(struct vector3 v1, struct vector3 v2);
float vector3TripleProduct(struct vector3 v, struct vector3 v1, struct vector3 v2);
struct vector3 vector3RotateAroundAxis(struct vector3 v, struct vector3 axis, float angle);
struct vector3 vector3RotateX(struct vector3 v, float angle);
struct vector3 vector3RotateY(struct vector3 v, float angle);
struct vector3 vector3RotateZ(struct vector3 v, float angle);
struct vector3 vector3Negate(struct vector3 v);
struct vector3 vector3Abs(struct vector3 v);
float vector3MaxComponent(struct vector3 v);
float vector3MinComponent(struct vector3 v);
struct vector3 vector3Pow(struct vector3 v, float exponent);
struct vector3 vector3Sqrt(struct vector3 v);
struct vector3 vector3Min(struct vector3 v1, struct vector3 v2);
struct vector3 vector3Max(struct vector3 v1, struct vector3 v2);
struct vector3 vector3Round(struct vector3 v);
struct vector3 vector3Floor(struct vector3 v);
struct vector3 vector3Ceil(struct vector3 v);
struct vector3 vector3Log(struct vector3 v);
struct vector3 vector3Exp(struct vector3 v);