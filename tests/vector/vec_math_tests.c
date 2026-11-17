#include <stdio.h>
#include <stdlib.h>

#include "test_utils.h"
#include "vector/vec_math.h"

static int failures = 0;

// == Helpers ==

// Componentwise approximate equality of two vectors.
static bool Vec2_approx_equal(Vec2 a, Vec2 b) {

  return approx_equal(a.x_coordinate, b.x_coordinate, ABS_TOL, REL_TOL) &&
         approx_equal(a.y_coordinate, b.y_coordinate, ABS_TOL, REL_TOL);
}

// == Vec2 math operations ==

/*
 * @brief Tests Vec2_sub
 *
 * @param a       vector a
 * @param b       vector b
 * @param result  vector a - b
 */
static bool test_Vec2_sub(Vec2 a, Vec2 b, Vec2 result) {

  Vec2 computed_difference = Vec2_sub(a, b);
  return Vec2_approx_equal(computed_difference, result);
}

/*
 * @brief Tests Vec2_norm_squared
 *
 * @param a       vector a
 * @param result  |a|^2
 */
static bool test_Vec2_norm_squared(Vec2 a, double result) {

  double computed_norm_squared = Vec2_norm_squared(a);
  return approx_equal(computed_norm_squared, result, ABS_TOL, REL_TOL);
}

/*
 * @brief Tests Vec2_norm
 *
 * @param a         vector a
 * @param result    |a|  
 */
static bool test_Vec2_norm(Vec2 a, double result) {

  double computed_norm = Vec2_norm(a);
  return approx_equal(computed_norm, result, ABS_TOL, REL_TOL);
}

int main(void) {

  // == Testing sub ==
  
  
}
