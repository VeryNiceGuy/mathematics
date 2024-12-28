#pragma once

struct Matrix4x4 {
	float m_11, m_12, m_13, m_14;
	float m_21, m_22, m_23, m_24;
	float m_31, m_32, m_33, m_34;
	float m_41, m_42, m_43, m_44;
};

struct Matrix4x4 matrix4x4_create_identity();
struct Matrix4x4 matrix4x4_create_look_at_lh(struct Vector3 eye, struct Vector3 at, struct Vector3 up);
struct Matrix4x4 matrix4x4_create_look_at_rh(struct Vector3 eye, struct Vector3 at, struct Vector3 up);
float matrix4x4_determinant(struct Matrix4x4 m);
struct Matrix4x4 matrix4x4_adjugate(struct Matrix4x4 m);
struct Matrix4x4 matrix4x4_inverse(struct Matrix4x4 m, int* success);
struct Matrix4x4 matrix4x4_transpose(struct Matrix4x4 m);
struct Matrix4x4 matrix4x4_add(struct Matrix4x4 a, struct Matrix4x4 b);
struct Matrix4x4 matrix4x4_subtract(struct Matrix4x4 a, struct Matrix4x4 b);
struct Matrix4x4 matrix4x4_multiply(struct Matrix4x4 a, struct Matrix4x4 b);
struct Matrix4x4 matrix4x4_multiplys(struct Matrix4x4 m, float scalar);
