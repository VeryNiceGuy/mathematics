#pragma once

struct matrix4x4 {
	float m_11, m_12, m_13, m_14;
	float m_21, m_22, m_23, m_24;
	float m_31, m_32, m_33, m_34;
	float m_41, m_42, m_43, m_44;
};

struct matrix4x4 matrix4x4CreateLookAtMatrixLH(struct vector3 eye, struct vector3 at, struct vector3 up);
struct matrix4x4 matrix4x4CreateLookAtMatrixRH(struct vector3 eye, struct vector3 at, struct vector3 up);
float matrix4x4Determinant(struct matrix4x4 m);
struct matrix4x4 matrix4x4Adjugate(struct matrix4x4 m);
struct matrix4x4 matrix4x4Inverse(struct matrix4x4 m, int* success);
struct matrix4x4 matrix4x4Transpose(struct matrix4x4 m);
struct matrix4x4 matrix4x4Add(struct matrix4x4 a, struct matrix4x4 b);
struct matrix4x4 matrix4x4Subtract(struct matrix4x4 a, struct matrix4x4 b);
struct matrix4x4 matrix4x4Multiply(struct matrix4x4 a, struct matrix4x4 b);
struct matrix4x4 matrix4x4MultiplyScalar(struct matrix4x4 m, float scalar);