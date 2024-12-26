#pragma once

struct matrix4x4 {
	float m_11, m_12, m_13, m_14;
	float m_21, m_22, m_23, m_24;
	float m_31, m_32, m_33, m_34;
	float m_41, m_42, m_43, m_44;
};

struct matrix4x4 createLookAtMatrixLH(struct vector3 eye, struct vector3 at, struct vector3 up);