#include "matrix4x4.h"
#include "vector3.h"

struct matrix4x4 createLookAtMatrixLH(struct vector3 eye, struct vector3 at, struct vector3 up) {
    struct vector3 zAxis = normalize(subtract(at, eye));
    struct vector3 xAxis = normalize(cross(up, zAxis));
    struct vector3 yAxis = cross(zAxis, xAxis);

    return (struct matrix4x4) {
        .m_11 = xAxis.x, .m_12 = yAxis.x, .m_13 = zAxis.x, .m_14 = 0.0f,
        .m_21 = xAxis.y, .m_22 = yAxis.y, .m_23 = zAxis.y, .m_24 = 0.0f,
        .m_31 = xAxis.z, .m_32 = yAxis.z, .m_33 = zAxis.z, .m_34 = 0.0f,

        .m_41 = -dot(xAxis, eye),
        .m_42 = -dot(yAxis, eye),
        .m_43 = -dot(zAxis, eye),
        .m_44 = 1.0f
    };
}

struct matrix4x4 createLookAtMatrixRH(struct vector3 eye, struct vector3 at, struct vector3 up) {
    struct vector3 zAxis = normalize(subtract(eye, at));
    struct vector3 xAxis = normalize(cross(up, zAxis));
    struct vector3 yAxis = cross(zAxis, xAxis);

    return (struct matrix4x4) {
        .m_11 = xAxis.x, .m_12 = yAxis.x, .m_13 = zAxis.x, .m_14 = 0.0f,
        .m_21 = xAxis.y, .m_22 = yAxis.y, .m_23 = zAxis.y, .m_24 = 0.0f,
        .m_31 = xAxis.z, .m_32 = yAxis.z, .m_33 = zAxis.z, .m_34 = 0.0f,

        .m_41 = -dot(xAxis, eye),
        .m_42 = -dot(yAxis, eye),
        .m_43 = -dot(zAxis, eye),
        .m_44 = 1.0f
    };
}

float determinant(struct matrix4x4 m) {
    return m.m_11 * (m.m_22 * (m.m_33 * m.m_44 - m.m_34 * m.m_43) - m.m_23 * (m.m_32 * m.m_44 - m.m_34 * m.m_42) + m.m_24 * (m.m_32 * m.m_43 - m.m_33 * m.m_42))
        - m.m_12 * (m.m_21 * (m.m_33 * m.m_44 - m.m_34 * m.m_43) - m.m_23 * (m.m_31 * m.m_44 - m.m_34 * m.m_41) + m.m_24 * (m.m_31 * m.m_43 - m.m_33 * m.m_41))
        + m.m_13 * (m.m_21 * (m.m_32 * m.m_44 - m.m_34 * m.m_42) - m.m_22 * (m.m_31 * m.m_44 - m.m_34 * m.m_41) + m.m_24 * (m.m_31 * m.m_42 - m.m_32 * m.m_41))
        - m.m_14 * (m.m_21 * (m.m_32 * m.m_43 - m.m_33 * m.m_42) - m.m_22 * (m.m_31 * m.m_43 - m.m_33 * m.m_41) + m.m_23 * (m.m_31 * m.m_42 - m.m_32 * m.m_41));
}

struct matrix4x4 adjugate(struct matrix4x4 m) {
    return (struct matrix4x4) {
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

struct matrix4x4 inverse(struct matrix4x4 m, int* success) {
    float det = determinant(m);
    if (det == 0) {
        *success = 0;
        return (struct matrix4x4) {0};
    }

    struct matrix4x4 adj = adjugate(m);
    float invDet = 1.0f / det;

    *success = 1;
    return (struct matrix4x4) {
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
