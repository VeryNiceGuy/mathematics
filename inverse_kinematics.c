#include "inverse_kinematics.h"
#include "vector2.h"
#include "vector3.h"
#include <math.h>

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

void ccd2(struct Chain2* chain, struct Vector2 target, float tolerance) {
    int max_iterations = 10;
    int iteration, i;

    for (iteration = 0; iteration < max_iterations; ++iteration) {
        for (i = chain->num_joints - 2; i >= 0; --i) {
            struct Vector2 to_effector = vector2_subtract(chain->joints[chain->num_joints - 1], chain->joints[i]);
            struct Vector2 to_target = vector2_subtract(target, chain->joints[i]);

            float cos_angle = vector2_dot(vector2_normalize(to_effector), vector2_normalize(to_target));
            if (cos_angle > 1.0f) {
                cos_angle = 1.0f;
            }

            if (cos_angle < -1.0f) {
                cos_angle = -1.0f;
            }

            float angle = acosf(cos_angle);
            float cross_product = to_effector.x * to_target.y - to_effector.y * to_target.x;

            if (cross_product < 0) {
                angle = -angle;
            }

            float sin_angle = sinf(angle);
            float cos_angle_rot = cosf(angle);

            struct Vector2 new_pos = {
                cos_angle_rot * to_effector.x - sin_angle * to_effector.y,
                sin_angle * to_effector.x + cos_angle_rot * to_effector.y
            };

            chain->joints[chain->num_joints - 1] = vector2_add(chain->joints[i], new_pos);

            if (vector2_distance_to(chain->joints[chain->num_joints - 1], target) < tolerance) {
                return;
            }
        }
    }
}

void ccd3(struct Chain3* chain, struct Vector3 target, float tolerance) {
    int max_iterations = 10;
    int iteration, i;

    for (iteration = 0; iteration < max_iterations; ++iteration) {
        for (i = chain->num_joints - 2; i >= 0; --i) {
            struct Vector3 to_effector = vector3_subtract(chain->joints[chain->num_joints - 1], chain->joints[i]);
            struct Vector3 to_target = vector3_subtract(target, chain->joints[i]);

            float cos_angle = vector3_dot(vector3_normalize(to_effector), vector3_normalize(to_target));
            if (cos_angle > 1.0f) {
                cos_angle = 1.0f;
            }

            if (cos_angle < -1.0f) {
                cos_angle = -1.0f;
            }

            float angle = acosf(cos_angle);

            struct Vector3 cross_product = vector3_cross(to_effector, to_target);
            if (vector3_magnitude(cross_product) < 1e-6) {
                continue;
            }

            cross_product = vector3_normalize(cross_product);

            for (int j = i + 1; j < chain->num_joints; ++j) {
                chain->joints[j] = vector3_add(chain->joints[i], vector3_rotate_around_axis(vector3_subtract(chain->joints[j], chain->joints[i]), cross_product, angle));
            }

            if (vector3_distance_to(chain->joints[chain->num_joints - 1], target) < tolerance) {
                return;
            }
        }
    }
}

void jacobian_ik(struct Chainj* chain, struct Vector2 target, float tolerance) {
    int max_iterations = 100;
    float lambda = 0.1f;

    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        struct Vector2 end_effector = chain->joints[chain->num_joints - 1];
        struct Vector2 error = vector2_subtract(target, end_effector);

        if (vector2_magnitude(error) < tolerance) {
            return;
        }

        for (int i = chain->num_joints - 1; i >= 0; --i) {
            struct Vector2 to_end_effector = vector2_subtract(end_effector, chain->joints[i]);
            struct Vector2 to_target = vector2_subtract(target, chain->joints[i]);

            float cross_product = to_end_effector.x * to_target.y - to_end_effector.y * to_target.x;
            float angle = atan2f(cross_product, vector2_dot(to_end_effector, to_target));

            chain->angles[i] += lambda * angle;

            for (int j = i; j < chain->num_joints; ++j) {
                chain->joints[j + 1] = vector2_add(chain->joints[j], vector2_rotate((struct Vector2) { chain->lengths[j], 0 }, chain->angles[j]));
            }

            end_effector = chain->joints[chain->num_joints - 1];
        }
    }
}

void jacobian_ik3(struct Chainj3* chain, struct Vector3 target, float tolerance) {
    int max_iterations = 100;
    float lambda = 0.1f;

    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        struct Vector3 end_effector = chain->joints[chain->num_joints - 1];
        struct Vector3 error = vector3_subtract(target, end_effector);

        if (vector3_magnitude(error) < tolerance) {
            return;
        }

        for (int i = chain->num_joints - 1; i >= 0; --i) {
            struct Vector3 to_end_effector = vector3_subtract(end_effector, chain->joints[i]);
            struct Vector3 to_target = vector3_subtract(target, chain->joints[i]);

            float cos_angle = vector3_dot(vector3_normalize(to_end_effector), vector3_normalize(to_target));
            if (cos_angle > 1.0f) {
                cos_angle = 1.0f;
            }

            if (cos_angle < -1.0f) {
                cos_angle = -1.0f;
            }

            float angle = acosf(cos_angle);

            struct Vector3 cross_product = vector3_cross(to_end_effector, to_target);
            if (vector3_magnitude(cross_product) < 1e-6) {
                continue;
            }

            cross_product = vector3_normalize(cross_product);

            for (int j = i + 1; j < chain->num_joints; ++j) {
                chain->joints[j] = vector3_add(chain->joints[i], vector3_rotate_around_axis(vector3_subtract(chain->joints[j], chain->joints[i]), cross_product, angle));
            }

            end_effector = chain->joints[chain->num_joints - 1];

            if (vector3_distance_to(end_effector, target) < tolerance) {
                return;
            }
        }
    }
}
