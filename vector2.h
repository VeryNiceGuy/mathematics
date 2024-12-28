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
float vector3_dot(struct Vector3 v1, struct Vector3 v2);