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
