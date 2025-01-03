#include "matrix4x4.h"
#include "vector3.h"
#include <math.h>

struct Matrix4x4 matrix4x4_create_identity() {
    return (struct Matrix4x4) {
        .m_11 = 1.0f, .m_12 = 0.0f, .m_13 = 0.0f, .m_14 = 0.0f,
        .m_21 = 0.0f, .m_22 = 1.0f, .m_23 = 0.0f, .m_24 = 0.0f,
        .m_31 = 0.0f, .m_32 = 0.0f, .m_33 = 1.0f, .m_34 = 0.0f,
        .m_41 = 0.0f, .m_32 = 0.0f, .m_33 = 1.0f, .m_44 = 1.0f,
    };
}

struct Matrix4x4 matrix4x4_create_look_at_lh(struct Vector3 eye, struct Vector3 at, struct Vector3 up) {
    struct Vector3 zAxis = vector3_normalize(vector3_subtract(at, eye));
    struct Vector3 xAxis = vector3_normalize(vector3_cross(up, zAxis));
    struct Vector3 yAxis = vector3_cross(zAxis, xAxis);

    return (struct Matrix4x4) {
        .m_11 = xAxis.x, .m_12 = yAxis.x, .m_13 = zAxis.x, .m_14 = 0.0f,
        .m_21 = xAxis.y, .m_22 = yAxis.y, .m_23 = zAxis.y, .m_24 = 0.0f,
        .m_31 = xAxis.z, .m_32 = yAxis.z, .m_33 = zAxis.z, .m_34 = 0.0f,

        .m_41 = -vector3_dot(xAxis, eye),
        .m_42 = -vector3_dot(yAxis, eye),
        .m_43 = -vector3_dot(zAxis, eye),
        .m_44 = 1.0f
    };
}

struct Matrix4x4 matrix4x4_create_look_at_rh(struct Vector3 eye, struct Vector3 at, struct Vector3 up) {
    struct Vector3 zAxis = vector3_normalize(vector3_subtract(eye, at));
    struct Vector3 xAxis = vector3_normalize(vector3_cross(up, zAxis));
    struct Vector3 yAxis = vector3_cross(zAxis, xAxis);

    return (struct Matrix4x4) {
        .m_11 = xAxis.x, .m_12 = yAxis.x, .m_13 = zAxis.x, .m_14 = 0.0f,
        .m_21 = xAxis.y, .m_22 = yAxis.y, .m_23 = zAxis.y, .m_24 = 0.0f,
        .m_31 = xAxis.z, .m_32 = yAxis.z, .m_33 = zAxis.z, .m_34 = 0.0f,

        .m_41 = -vector3_dot(xAxis, eye),
        .m_42 = -vector3_dot(yAxis, eye),
        .m_43 = -vector3_dot(zAxis, eye),
        .m_44 = 1.0f
    };
}

struct Matrix4x4 matrix4x4_perspective_fov_lh_d3d(float fovY, float aspect, float nearZ, float farZ) {
    float h = 1.0f / tanf(fovY / 2.0f);
    float w = h / aspect;

    float depth = farZ - nearZ;
    float q = farZ / depth;

    return (struct Matrix4x4) {
        .m_11 = w, .m_12 = 0.0f, .m_13 = 0.0f, .m_14 = 0.0f,
        .m_21 = 0.0f, .m_22 = h, .m_23 = 0.0f, .m_24 = 0.0f,
        .m_31 = 0.0f, .m_32 = 0.0f, .m_33 = q, .m_34 = 1.0f,
        .m_41 = 0.0f, .m_42 = 0.0f, .m_43 = -nearZ * q, .m_44 = 0.0f
    };
}

struct Matrix4x4 matrix4x4_perspective_fov_rh_d3d(float fovY, float aspect, float nearZ, float farZ) {
    float h = 1.0f / tanf(fovY / 2.0f);
    float w = h / aspect;

    float depth = nearZ - farZ;
    float q = farZ / depth;

    return (struct Matrix4x4) {
        .m_11 = w, .m_12 = 0.0f, .m_13 = 0.0f, .m_14 = 0.0f,
        .m_21 = 0.0f, .m_22 = h, .m_23 = 0.0f, .m_24 = 0.0f,
        .m_31 = 0.0f, .m_32 = 0.0f, .m_33 = q, .m_34 = -1.0f,
        .m_41 = 0.0f, .m_42 = 0.0f, .m_43 = nearZ * q, .m_44 = 0.0f
    };
}

struct Matrix4x4 matrix4x4_perspective_fov_lh_gl(float fovY, float aspect, float nearZ, float farZ) {
    float h = 1.0f / tanf(fovY / 2.0f);
    float w = h / aspect;

    float depth = farZ - nearZ;
    float q = (farZ + nearZ) / depth;
    float qn = (2 * farZ * nearZ) / depth;

    return (struct Matrix4x4) {
        .m_11 = w, .m_12 = 0.0f, .m_13 = 0.0f, .m_14 = 0.0f,
        .m_21 = 0.0f, .m_22 = h, .m_23 = 0.0f, .m_24 = 0.0f,
        .m_31 = 0.0f, .m_32 = 0.0f, .m_33 = q, .m_34 = 1.0f,
        .m_41 = 0.0f, .m_42 = 0.0f, .m_43 = -qn, .m_44 = 0.0f
    };
}


struct Matrix4x4 matrix4x4_perspective_fov_rh_gl(float fovY, float aspect, float nearZ, float farZ) {
    float h = 1.0f / tanf(fovY / 2.0f);
    float w = h / aspect;

    float depth = nearZ - farZ;
    float q = (farZ + nearZ) / depth;
    float qn = (2 * farZ * nearZ) / depth;

    return (struct Matrix4x4) {
        .m_11 = w, .m_12 = 0.0f, .m_13 = 0.0f, .m_14 = 0.0f,
        .m_21 = 0.0f, .m_22 = h, .m_23 = 0.0f, .m_24 = 0.0f,
        .m_31 = 0.0f, .m_32 = 0.0f, .m_33 = q, .m_34 = -1.0f,
        .m_41 = 0.0f, .m_42 = 0.0f, .m_43 = qn, .m_44 = 0.0f
    };
}


float matrix4x4_determinant(struct Matrix4x4 m) {
    return m.m_11 * (m.m_22 * (m.m_33 * m.m_44 - m.m_34 * m.m_43) - m.m_23 * (m.m_32 * m.m_44 - m.m_34 * m.m_42) + m.m_24 * (m.m_32 * m.m_43 - m.m_33 * m.m_42))
        - m.m_12 * (m.m_21 * (m.m_33 * m.m_44 - m.m_34 * m.m_43) - m.m_23 * (m.m_31 * m.m_44 - m.m_34 * m.m_41) + m.m_24 * (m.m_31 * m.m_43 - m.m_33 * m.m_41))
        + m.m_13 * (m.m_21 * (m.m_32 * m.m_44 - m.m_34 * m.m_42) - m.m_22 * (m.m_31 * m.m_44 - m.m_34 * m.m_41) + m.m_24 * (m.m_31 * m.m_42 - m.m_32 * m.m_41))
        - m.m_14 * (m.m_21 * (m.m_32 * m.m_43 - m.m_33 * m.m_42) - m.m_22 * (m.m_31 * m.m_43 - m.m_33 * m.m_41) + m.m_23 * (m.m_31 * m.m_42 - m.m_32 * m.m_41));
}

struct Matrix4x4 matrix4x4_adjugate(struct Matrix4x4 m) {
    return (struct Matrix4x4) {
        .m_11 = m.m_22 * (m.m_33 * m.m_44 - m.m_34 * m.m_43) - m.m_23 * (m.m_32 * m.m_44 - m.m_34 * m.m_42) + m.m_24 * (m.m_32 * m.m_43 - m.m_33 * m.m_42),
        .m_12 = -m.m_12 * (m.m_33 * m.m_44 - m.m_34 * m.m_43) + m.m_13 * (m.m_32 * m.m_44 - m.m_34 * m.m_42) - m.m_14 * (m.m_32 * m.m_43 - m.m_33 * m.m_42),
        .m_13 = m.m_12 * (m.m_23 * m.m_44 - m.m_24 * m.m_43) - m.m_13 * (m.m_22 * m.m_44 - m.m_24 * m.m_42) + m.m_14 * (m.m_22 * m.m_43 - m.m_23 * m.m_42),
        .m_14 = -m.m_12 * (m.m_23 * m.m_34 - m.m_24 * m.m_33) + m.m_13 * (m.m_22 * m.m_34 - m.m_24 * m.m_32) - m.m_14 * (m.m_22 * m.m_33 - m.m_23 * m.m_32),

        .m_21 = -m.m_21 * (m.m_33 * m.m_44 - m.m_34 * m.m_43) + m.m_23 * (m.m_31 * m.m_44 - m.m_34 * m.m_41) - m.m_24 * (m.m_31 * m.m_43 - m.m_33 * m.m_41),
        .m_22 = m.m_11 * (m.m_33 * m.m_44 - m.m_34 * m.m_43) - m.m_13 * (m.m_31 * m.m_44 - m.m_34 * m.m_41) + m.m_14 * (m.m_31 * m.m_43 - m.m_33 * m.m_41),
        .m_23 = -m.m_11 * (m.m_23 * m.m_44 - m.m_24 * m.m_43) + m.m_13 * (m.m_21 * m.m_44 - m.m_24 * m.m_41) - m.m_14 * (m.m_21 * m.m_43 - m.m_23 * m.m_41),
        .m_24 = m.m_11 * (m.m_23 * m.m_34 - m.m_24 * m.m_33) - m.m_13 * (m.m_21 * m.m_34 - m.m_24 * m.m_31) + m.m_14 * (m.m_21 * m.m_33 - m.m_23 * m.m_31),

        .m_31 = m.m_21 * (m.m_32 * m.m_44 - m.m_34 * m.m_42) - m.m_22 * (m.m_31 * m.m_44 - m.m_34 * m.m_41) + m.m_24 * (m.m_31 * m.m_42 - m.m_32 * m.m_41),
        .m_32 = -m.m_11 * (m.m_32 * m.m_44 - m.m_34 * m.m_42) + m.m_12 * (m.m_31 * m.m_44 - m.m_34 * m.m_41) - m.m_14 * (m.m_31 * m.m_42 - m.m_32 * m.m_41),
        .m_33 = m.m_11 * (m.m_22 * m.m_44 - m.m_24 * m.m_42) - m.m_12 * (m.m_21 * m.m_44 - m.m_24 * m.m_41) + m.m_14 * (m.m_21 * m.m_42 - m.m_22 * m.m_41),
        .m_34 = -m.m_11 * (m.m_22 * m.m_34 - m.m_24 * m.m_32) + m.m_12 * (m.m_21 * m.m_34 - m.m_24 * m.m_31) - m.m_14 * (m.m_21 * m.m_32 - m.m_22 * m.m_31),

        .m_41 = -m.m_21 * (m.m_32 * m.m_43 - m.m_33 * m.m_42) + m.m_22 * (m.m_31 * m.m_43 - m.m_33 * m.m_41) - m.m_23 * (m.m_31 * m.m_42 - m.m_32 * m.m_41),
        .m_42 = m.m_11 * (m.m_32 * m.m_43 - m.m_33 * m.m_42) - m.m_12 * (m.m_31 * m.m_43 - m.m_33 * m.m_41) + m.m_13 * (m.m_31 * m.m_42 - m.m_32 * m.m_41),
        .m_43 = -m.m_11 * (m.m_22 * m.m_43 - m.m_23 * m.m_42) + m.m_12 * (m.m_21 * m.m_43 - m.m_23 * m.m_41) - m.m_13 * (m.m_21 * m.m_42 - m.m_22 * m.m_41),
        .m_44 = m.m_11 * (m.m_22 * m.m_33 - m.m_23 * m.m_32) - m.m_12 * (m.m_21 * m.m_33 - m.m_23 * m.m_31) + m.m_13 * (m.m_21 * m.m_32 - m.m_22 * m.m_31)
    };
}

struct Matrix4x4 matrix4x4_inverse(struct Matrix4x4 m, int* success) {
    float det = matrix4x4_determinant(m);
    if (det == 0) {
        *success = 0;
        return (struct Matrix4x4) {0};
    }

    struct Matrix4x4 adj = matrix4x4_adjugate(m);
    float invDet = 1.0f / det;

    *success = 1;
    return (struct Matrix4x4) {
        .m_11 = adj.m_11 * invDet,
        .m_12 = adj.m_12 * invDet,
        .m_13 = adj.m_13 * invDet,
        .m_14 = adj.m_14 * invDet,
        .m_21 = adj.m_21 * invDet,
        .m_22 = adj.m_22 * invDet,
        .m_23 = adj.m_23 * invDet,
        .m_24 = adj.m_24 * invDet,
        .m_31 = adj.m_31 * invDet,
        .m_32 = adj.m_32 * invDet,
        .m_33 = adj.m_33 * invDet,
        .m_34 = adj.m_34 * invDet,
        .m_41 = adj.m_41 * invDet,
        .m_42 = adj.m_42 * invDet,
        .m_43 = adj.m_43 * invDet,
        .m_44 = adj.m_44 * invDet
    };
}

struct Matrix4x4 matrix4x4_transpose(struct Matrix4x4 m) {
    return (struct Matrix4x4) {
        .m_11 = m.m_11, .m_12 = m.m_21, .m_13 = m.m_31, .m_14 = m.m_41,
        .m_21 = m.m_12, .m_22 = m.m_22, .m_23 = m.m_32, .m_24 = m.m_42,
        .m_31 = m.m_13, .m_32 = m.m_23, .m_33 = m.m_33, .m_34 = m.m_43,
        .m_41 = m.m_14, .m_42 = m.m_24, .m_43 = m.m_34, .m_44 = m.m_44
    };
}

struct Matrix4x4 matrix4x4_add(struct Matrix4x4 a, struct Matrix4x4 b) {
    return (struct Matrix4x4) {
        .m_11 = a.m_11 + b.m_11, .m_12 = a.m_12 + b.m_12, .m_13 = a.m_13 + b.m_13, .m_14 = a.m_14 + b.m_14,
        .m_21 = a.m_21 + b.m_21, .m_22 = a.m_22 + b.m_22, .m_23 = a.m_23 + b.m_23, .m_24 = a.m_24 + b.m_24,
        .m_31 = a.m_31 + b.m_31, .m_32 = a.m_32 + b.m_32, .m_33 = a.m_33 + b.m_33, .m_34 = a.m_34 + b.m_34,
        .m_41 = a.m_41 + b.m_41, .m_42 = a.m_42 + b.m_42, .m_43 = a.m_43 + b.m_43, .m_44 = a.m_44 + b.m_44
    };
}

struct Matrix4x4 matrix4x4_subtract(struct Matrix4x4 a, struct Matrix4x4 b) {
    return (struct Matrix4x4) {
        .m_11 = a.m_11 - b.m_11, .m_12 = a.m_12 - b.m_12, .m_13 = a.m_13 - b.m_13, .m_14 = a.m_14 - b.m_14,
        .m_21 = a.m_21 - b.m_21, .m_22 = a.m_22 - b.m_22, .m_23 = a.m_23 - b.m_23, .m_24 = a.m_24 - b.m_24,
        .m_31 = a.m_31 - b.m_31, .m_32 = a.m_32 - b.m_32, .m_33 = a.m_33 - b.m_33, .m_34 = a.m_34 - b.m_34,
        .m_41 = a.m_41 - b.m_41, .m_42 = a.m_42 - b.m_42, .m_43 = a.m_43 - b.m_43, .m_44 = a.m_44 - b.m_44
    };
}

struct Matrix4x4 matrix4x4_multiply(struct Matrix4x4 a, struct Matrix4x4 b) {
    return (struct Matrix4x4) {
        .m_11 = a.m_11 * b.m_11 + a.m_12 * b.m_21 + a.m_13 * b.m_31 + a.m_14 * b.m_41,
        .m_12 = a.m_11 * b.m_12 + a.m_12 * b.m_22 + a.m_13 * b.m_32 + a.m_14 * b.m_42,
        .m_13 = a.m_11 * b.m_13 + a.m_12 * b.m_23 + a.m_13 * b.m_33 + a.m_14 * b.m_43,
        .m_14 = a.m_11 * b.m_14 + a.m_12 * b.m_24 + a.m_13 * b.m_34 + a.m_14 * b.m_44,

        .m_21 = a.m_21 * b.m_11 + a.m_22 * b.m_21 + a.m_23 * b.m_31 + a.m_24 * b.m_41,
        .m_22 = a.m_21 * b.m_12 + a.m_22 * b.m_22 + a.m_23 * b.m_32 + a.m_24 * b.m_42,
        .m_23 = a.m_21 * b.m_13 + a.m_22 * b.m_23 + a.m_23 * b.m_33 + a.m_24 * b.m_43,
        .m_24 = a.m_21 * b.m_14 + a.m_22 * b.m_24 + a.m_23 * b.m_34 + a.m_24 * b.m_44,

        .m_31 = a.m_31 * b.m_11 + a.m_32 * b.m_21 + a.m_33 * b.m_31 + a.m_34 * b.m_41,
        .m_32 = a.m_31 * b.m_12 + a.m_32 * b.m_22 + a.m_33 * b.m_32 + a.m_34 * b.m_42,
        .m_33 = a.m_31 * b.m_13 + a.m_32 * b.m_23 + a.m_33 * b.m_33 + a.m_34 * b.m_43,
        .m_34 = a.m_31 * b.m_14 + a.m_32 * b.m_24 + a.m_33 * b.m_34 + a.m_34 * b.m_44,

        .m_41 = a.m_41 * b.m_11 + a.m_42 * b.m_21 + a.m_43 * b.m_31 + a.m_44 * b.m_41,
        .m_42 = a.m_41 * b.m_12 + a.m_42 * b.m_22 + a.m_43 * b.m_32 + a.m_44 * b.m_42,
        .m_43 = a.m_41 * b.m_13 + a.m_42 * b.m_23 + a.m_43 * b.m_33 + a.m_44 * b.m_43,
        .m_44 = a.m_41 * b.m_14 + a.m_42 * b.m_24 + a.m_43 * b.m_34 + a.m_44 * b.m_44
    };
}

struct Matrix4x4 matrix4x4_multiply_scalar(struct Matrix4x4 m, float scalar) {
    return (struct Matrix4x4) {
        .m_11 = m.m_11 * scalar, .m_12 = m.m_12 * scalar, .m_13 = m.m_13 * scalar, .m_14 = m.m_14 * scalar,
        .m_21 = m.m_21 * scalar, .m_22 = m.m_22 * scalar, .m_23 = m.m_23 * scalar, .m_24 = m.m_24 * scalar,
        .m_31 = m.m_31 * scalar, .m_32 = m.m_32 * scalar, .m_33 = m.m_33 * scalar, .m_34 = m.m_34 * scalar,
        .m_41 = m.m_41 * scalar, .m_42 = m.m_42 * scalar, .m_43 = m.m_43 * scalar, .m_44 = m.m_44 * scalar
    };
}
