// Test module for vectors. It tests every single vector operation.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "test_utils.h"
#include "vector/vec.h"

// Tolerances for computed values. DBL_EPSILON is too tight for results that
// went through several floating-point operations.
#define ABS_TOL 1e-12
#define REL_TOL 1e-12

static int failures = 0;


// == Helpers ==

// Componentwise approximate equality of two vectors.
static bool Vec2_approx_equal(Vec2 a, Vec2 b) {

  return approx_equal(a.x_coordinate, b.x_coordinate, ABS_TOL, REL_TOL) &&
         approx_equal(a.y_coordinate, b.y_coordinate, ABS_TOL, REL_TOL);
}

// == Vec2 base operations ==

// Tests Vec2_create()
//
// x_coordinate:  input x_coordinate
// y_coordinate:  input y_coordinate
// vector:        precomputed vector with the same coordinates
static bool test_Vec2_create(double x_coordinate, double y_coordinate,
                             Vec2 vector) {

  Vec2 created_vec2 = Vec2_create(x_coordinate, y_coordinate);
  return Vec2_approx_equal(created_vec2, vector);
}

// Tests Vec2_add()
//
// a:        first input vector
// b:        second input vector
// sum_a_b:  precomputed sum
static bool test_Vec2_add(Vec2 a, Vec2 b, Vec2 sum_a_b) {

  // addition is commutative, so check both orders
  return Vec2_approx_equal(Vec2_add(a, b), sum_a_b) &&
         Vec2_approx_equal(Vec2_add(b, a), sum_a_b);
}

// Tests Vec2_scale()
//
// a:    input vector
// s:    input scalar
// s_a:  precomputed scaled vector
static bool test_Vec2_scale(Vec2 a, double s, Vec2 s_a) {

  return Vec2_approx_equal(Vec2_scale(a, s), s_a);
}

// Tests Vec2_dot()
//
// a:        first input vector
// b:        second input vector
// a_dot_b:  precomputed dot product
static bool test_Vec2_dot(Vec2 a, Vec2 b, double a_dot_b) {

  // the dot product is commutative, so check both orders
  return approx_equal(Vec2_dot(a, b), a_dot_b, ABS_TOL, REL_TOL) &&
         approx_equal(Vec2_dot(b, a), a_dot_b, ABS_TOL, REL_TOL);
}

// == Test cases ==

int main(void) {

  // create
  CHECK(test_Vec2_create(1, 2, (Vec2){1, 2}));
  CHECK(test_Vec2_create(0, 0, (Vec2){0, 0}));
  CHECK(test_Vec2_create(-3.5, 4.25, (Vec2){-3.5, 4.25}));

  // add
  CHECK(test_Vec2_add(Vec2_create(1, 2), Vec2_create(3, 4), Vec2_create(4, 6)));
  CHECK(test_Vec2_add(Vec2_create(1, 2), Vec2_create(0, 0), Vec2_create(1, 2)));
  CHECK(test_Vec2_add(Vec2_create(1, -2), Vec2_create(-1, 2), Vec2_create(0, 0)));
  CHECK(test_Vec2_add(Vec2_create(0.1, 0.2), Vec2_create(0.2, 0.1), Vec2_create(0.3, 0.3)));

  // scale
  CHECK(test_Vec2_scale(Vec2_create(1, -2), 2, Vec2_create(2, -4)));
  CHECK(test_Vec2_scale(Vec2_create(1, -2), 0, Vec2_create(0, 0)));
  CHECK(test_Vec2_scale(Vec2_create(1, -2), -1, Vec2_create(-1, 2)));
  CHECK(test_Vec2_scale(Vec2_create(3, 4), 0.5, Vec2_create(1.5, 2)));

  // dot
  CHECK(test_Vec2_dot(Vec2_create(1, 2), Vec2_create(3, 4), 11));
  CHECK(test_Vec2_dot(Vec2_create(1, 0), Vec2_create(0, 1), 0));   // perpendicular
  CHECK(test_Vec2_dot(Vec2_create(3, 4), Vec2_create(3, 4), 25));  // a . a
  CHECK(test_Vec2_dot(Vec2_create(1, 2), Vec2_create(-2, 1), 0));  // perpendicular
  CHECK(test_Vec2_dot(Vec2_create(0, 0), Vec2_create(5, 7), 0));

  if (failures == 0) {
    printf("test_vec: all tests passed\n");
    return EXIT_SUCCESS;
  }

  printf("test_vec: %d failure(s)\n", failures);
  return EXIT_FAILURE;
}
