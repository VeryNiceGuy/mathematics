#include "inverse_kinematics.h"
#include "vector2.h"
#include "vector3.h"

void fabrik2(struct Chain2* chain, struct Vector2 target, float tolerance) {
    int max_iterations = 10;
    int i, iteration;
    float dist = vector2_distance_to(chain->joints[0], target);

    if (dist > chain->lengths[0]) {
        for (i = 0; i < chain->num_joints - 1; ++i) {
            float r = vector2_distance_to(chain->joints[i], target);
            float lambda = chain->lengths[i] / r;
            chain->joints[i + 1] = vector2_add(chain->joints[i], vector2_multiplys(vector2_subtract(target, chain->joints[i]), lambda));
        }
    }
    else {
        for (iteration = 0; iteration < max_iterations; ++iteration) {
            chain->joints[chain->num_joints - 1] = target;

            for (i = chain->num_joints - 2; i >= 0; --i) {
                float r = vector2_distance_to(chain->joints[i + 1], chain->joints[i]);
                float lambda = chain->lengths[i] / r;
                chain->joints[i] = vector2_add(chain->joints[i + 1], vector2_multiplys(vector2_subtract(chain->joints[i], chain->joints[i + 1]), lambda));
            }

            chain->joints[0] = (struct Vector2){ 0, 0 };

            for (i = 0; i < chain->num_joints - 1; ++i) {
                float r = vector2_distance_to(chain->joints[i + 1], chain->joints[i]);
                float lambda = chain->lengths[i] / r;
                chain->joints[i + 1] = vector2_add(chain->joints[i], vector2_multiplys(vector2_subtract(chain->joints[i + 1], chain->joints[i]), lambda));
            }

            if (vector2_distance_to(chain->joints[chain->num_joints - 1], target) < tolerance) {
                break;
            }
        }
    }
}


void fabrik3(struct Chain3* chain, struct Vector3 target, float tolerance) {
    int max_iterations = 10;
    int i, iteration;
    float dist = vector3_distance_to(chain->joints[0], target);

    if (dist > chain->lengths[0]) {
        for (i = 0; i < chain->num_joints - 1; ++i) {
            float r = vector3_distance_to(chain->joints[i], target);
            float lambda = chain->lengths[i] / r;
            chain->joints[i + 1] = vector3_add(chain->joints[i], vector3_multiplys(vector3_subtract(target, chain->joints[i]), lambda));
        }
    }
    else {
        for (iteration = 0; iteration < max_iterations; ++iteration) {
            chain->joints[chain->num_joints - 1] = target;

            for (i = chain->num_joints - 2; i >= 0; --i) {
                float r = vector3_distance_to(chain->joints[i + 1], chain->joints[i]);
                float lambda = chain->lengths[i] / r;
                chain->joints[i] = vector3_add(chain->joints[i + 1], vector3_multiplys(vector3_subtract(chain->joints[i], chain->joints[i + 1]), lambda));
            }

            chain->joints[0] = (struct Vector3){ 0, 0, 0 };

            for (i = 0; i < chain->num_joints - 1; ++i) {
                float r = vector3_distance_to(chain->joints[i + 1], chain->joints[i]);
                float lambda = chain->lengths[i] / r;
                chain->joints[i + 1] = vector3_add(chain->joints[i], vector3_multiplys(vector3_subtract(chain->joints[i + 1], chain->joints[i]), lambda));
            }

            if (vector3_distance_to(chain->joints[chain->num_joints - 1], target) < tolerance) {
                break;
            }
        }
    }
}
