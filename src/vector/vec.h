/**
 * @file vec.h
 * @brief vector definitions.
 *
 * This module only defines vectors and the basic operations they satisfy.
 *
 * This is _unitless_, units are only enforced by the user.
 */

#ifndef VEC_H
#define VEC_H

// == VECTOR2 STRUCT & METHODS == //

/** @brief A 2D vector $(x, y)$ in Cartesian components. */
typedef struct {
  double x_coordinate;  ///< first component
  double y_coordinate;  ///< second component
} Vec2;

/**
 * @brief Creates a Vec2 struct and returns it
 *
 * @param x_coordinate  x_coordinate of the vector
 * @param y_coordinate  y_coordinate of the vector
 */
Vec2 Vec2_create(double x_coordinate, double y_coordinate);

/**
 * @brief Returns the vector sum $a + b = (a_x + b_x,\ a_y + b_y)$.
 * @param a  first summand
 * @param b  second summand
 * @return   the sum, as a new vector
 */
Vec2 Vec2_add(Vec2 a, Vec2 b);

/**
 * @brief Returns the scaled vector $s\,a = (s\,a_x,\ s\,a_y)$.
 * @param a  vector to scale
 * @param s  scalar multiplier
 * @return   the scaled vector, as a new vector
 */
Vec2 Vec2_scale(Vec2 a, double s);

/**
 * @brief Returns the dot product $a \cdot b = a_x b_x + a_y b_y$.
 *
 * Also gives the squared length: $\lVert a \rVert^2 = a \cdot a$.
 *
 * @param a  first vector
 * @param b  second vector
 * @return   the dot product (a scalar)
 */
double Vec2_dot(Vec2 a, Vec2 b);

#endif /* VEC_H */
