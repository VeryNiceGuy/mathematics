#pragma once

struct Vector2 {
	float x, y;
};

struct Vector2 vector2_normalize(struct Vector2 v);
float vector2_magnitude(struct Vector2 v);
struct Vector2 vector2_add(struct Vector2 v1, struct Vector2 v2);
struct Vector2 vector2_adds(struct Vector2 v, float s);
struct Vector2 vector2_subtract(struct Vector2 v1, struct Vector2 v2);
struct Vector2 vector2_subtracts(struct Vector2 v, float s);
struct Vector2 vector2_multiply(struct Vector2 v1, struct Vector2 v2);
struct Vector2 vector2_multiplys(struct Vector2 v, float s);
struct Vector2 vector2_divide(struct Vector2 v1, struct Vector2 v2);
struct Vector2 vector2_divides(struct Vector2 v, float s);
float vector2_cross(struct Vector2 a, struct Vector2 b);
float vector2_dot(struct Vector2 v1, struct Vector2 v2);
float vector2_distance_to(struct Vector2 a, struct Vector2 b);
struct Vector2 vector2_rotate(struct Vector2 v, float angle);
struct Vector2 vector2_negate(struct Vector2 v);
struct Vector2 vector2_abs(struct Vector2 v);
float vector2_max_component(struct Vector2 v);
float vector2_min_component(struct Vector2 v);
struct Vector2 vector2_pow(struct Vector2 v, float exponent);
struct Vector2 vector2_sqrt(struct Vector2 v);
struct Vector2 vector2_min(struct Vector2 v1, struct Vector2 v2);
struct Vector2 vector3_max(struct Vector2 v1, struct Vector2 v2);
struct Vector2 vector2_round(struct Vector2 v);
struct Vector2 vector2_floor(struct Vector2 v);
struct Vector2 vector2_ceil(struct Vector2 v);
struct Vector2 vector2_log(struct Vector2 v);
struct Vector2 vector2_exp(struct Vector2 v);
