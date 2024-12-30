#pragma once

struct Vector2;
struct Vector3;

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

void fabrik2(struct Chain2* chain, struct Vector2 target, float tolerance);
void fabrik3(struct Chain3* chain, struct Vector3 target, float tolerance);
