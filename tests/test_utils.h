// Minimal test helpers: assertions, float comparison and result reporting.
//
// Each test executable is a single translation unit, so the state here is
// `static` and nothing needs a matching .c file.

#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Default tolerances. A test file can #define these before including this
// header to override them.
#ifndef ABS_TOL
#define ABS_TOL 1e-12
#endif

#ifndef REL_TOL
#define REL_TOL 1e-12
#endif

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

// True if a and b are within max(abs_tol, rel_tol * max(|a|, |b|)).
static inline bool approx_equal(double a, double b, double abs_tol,
                                double rel_tol) {
  double difference = fabs(a - b);
  double scale = fmax(fabs(a), fabs(b));
  return difference <= fmax(abs_tol, rel_tol * scale);
}

#endif
