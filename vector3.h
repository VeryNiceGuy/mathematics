#pragma once

struct Vector3 {
    float x, y, z;
};

struct Vector3 vector3_normalize(struct Vector3 v);
float vector3_magnitude(struct Vector3 v);
struct Vector3 vector3_add(struct Vector3 v1, struct Vector3 v2);
struct Vector3 vector3_add_scalar(struct Vector3 v, float s);
struct Vector3 vector3_subtract(struct Vector3 v1, struct Vector3 v2);
struct Vector3 vector3_subtract_scalar(struct Vector3 v, float s);
struct Vector3 vector3_multiply(struct Vector3 v1, struct Vector3 v2);
struct Vector3 vector3_multiply_scalar(struct Vector3 v, float s);
struct Vector3 vector3_divide(struct Vector3 v1, struct Vector3 v2);
struct Vector3 vector3_divide_scalar(struct Vector3 v, float s);
struct Vector3 vector3_cross(struct Vector3 v1, struct Vector3 v2);
float vector3_dot(struct Vector3 v1, struct Vector3 v2);
float vector3_distance_to(struct Vector3 v1, struct Vector3 v2);
float vector3_angle_between(struct Vector3 v1, struct Vector3 v2);
float vector3_angle_to(struct Vector3 v1, struct Vector3 v2);
struct Vector3 vector3_reflect(struct Vector3 v, struct Vector3 normal);
struct Vector3 vector3_lerp(struct Vector3 v1, struct Vector3 v2, float t);
struct Vector3 vector3_clamp(struct Vector3 v, struct Vector3 min, struct Vector3 max);
struct Vector3 vector3_midpoint(struct Vector3 v1, struct Vector3 v2);
struct Vector3 vector3_project_onto(struct Vector3 v1, struct Vector3 v2);
struct Vector3 vector3_perpendicular_to(struct Vector3 v1, struct Vector3 v2);
float vector3_triple_product(struct Vector3 v, struct Vector3 v1, struct Vector3 v2);
struct Vector3 vector3_rotate_around_axis(struct Vector3 v, struct Vector3 axis, float angle);
struct Vector3 vector3_rotate_x(struct Vector3 v, float angle);
struct Vector3 vector3_rotate_y(struct Vector3 v, float angle);
struct Vector3 vector3_rotate_z(struct Vector3 v, float angle);
struct Vector3 vector3_negate(struct Vector3 v);
struct Vector3 vector3_abs(struct Vector3 v);
float vector3_max_component(struct Vector3 v);
float vector3_min_component(struct Vector3 v);
struct Vector3 vector3_pow(struct Vector3 v, float exponent);
struct Vector3 vector3_sqrt(struct Vector3 v);
struct Vector3 vector3_min(struct Vector3 v1, struct Vector3 v2);
struct Vector3 vector3_max(struct Vector3 v1, struct Vector3 v2);
struct Vector3 vector3_round(struct Vector3 v);
struct Vector3 vector3_floor(struct Vector3 v);
struct Vector3 vector3_ceil(struct Vector3 v);
struct Vector3 vector3_log(struct Vector3 v);
struct Vector3 vector3_exp(struct Vector3 v);
