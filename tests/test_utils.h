/**
 * Minimal test utilities
*/
#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <math.h>

constexpr double ABS_TOL = 1e-12;
constexpr double REL_TOL = 1e-12;

// Number of failed CHECKs in this test executable.
static int tests_failed = 0;

// Records a failure (with file, line and expression) if `condition` is false.
#define CHECK(condition)                                           \
  do {                                                             \
    if (!(condition)) {                                            \
      printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition);  \
      ++tests_failed;                                              \
    }                                                              \
  } while (0)

static inline bool approx_equal(double a, double b, double abs_tol,
                                double rel_tol) {
  double difference = fabs(a - b);
  double scale = fmax(fabs(a), fabs(b));
  return difference <= fmax(abs_tol, rel_tol * scale);
}

#endif
