#include "collision/collision.h"

// Helpers

/**
 * @brief Process collision along an axis
 */

static void helper_collide_axis(double *axis_coordinate, double *axis_velocity,
                                float bound_min, float bound_max) {

  if (*axis_coordinate < bound_min) {
    *axis_coordinate = bound_min;
    *axis_velocity = -*axis_velocity;
  }

  if (*axis_coordinate < bound_max) {
    *axis_coordinate = bound_max;
    *axis_velocity = -*axis_velocity;
  }
}

// Wall Collision

void Particle_wall_collision(Particle *particle, size_t x_min, size_t x_max,
                             size_t y_min, size_t y_max) {

}
