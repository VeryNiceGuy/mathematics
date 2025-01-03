#pragma once

#include "vector2.h"
#include "vector3.h"

struct Chain2 {
    struct Vector2* joints;
    int num_joints;
    float* lengths;
};

struct Chain3 {
    struct Vector3* joints;
    int num_joints;
    float* lengths;
};

struct Chainj {
    struct Vector2* joints;
    float* angles;
    int num_joints;
    float* lengths;
};

struct Chainj3 {
    struct Vector3* joints;
    float* angles;
    int num_joints;
    float* lengths;
};

void fabrik2(struct Chain2* chain, struct Vector2 target, float tolerance);
void fabrik3(struct Chain3* chain, struct Vector3 target, float tolerance);

void ccd2(struct Chain2* chain, struct Vector2 target, float tolerance);
void ccd3(struct Chain3* chain, struct Vector3 target, float tolerance);

void jacobian_ik(struct Chainj* chain, struct Vector2 target, float tolerance);
void jacobian_ik3(struct Chainj3* chain, struct Vector3 target, float tolerance);