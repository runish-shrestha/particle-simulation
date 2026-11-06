/**
 * @file vec_math.h
 * @brief additional vector operations
 *
 * This module defines additional vector methods.
 *
 * The methods here are non-elementary i.e., they are derived from basic Vec2 opertions
 *
*/

#ifndef VEC_MATH_H
#define VEC_MATH_H

#include "vector/vec.h"

/**
 * @brief computes the differnece of vectors $vector_1 - vector_2$
 * 
 * @param vector1       vector 1
 * @param vector2       vector 2
 *
 * @return difference   vector difference vector1 - vector2 
 */
Vec2 Vec2_sub(Vec2 vector1, Vec2 vector2);

/** 
 * @brief computes the square length of the Vec2 vector given by $\lVert a \rVert^2 = a_x^2+a_y^2$
 *
 * @param a vector whose length to compute
 * @returns length/norm squared of the vector
 */
double Vec2_norm_squared(Vec2 a);

/**
 * @brief computes the length of the Vec2 vector given by $\lVert a \rVert = \sqrt{a_x^2+a_y^2}$
 *
 * @param a vector whose length to compute
 * @returns length/norm of the vector
 */
double Vec2_norm(Vec2 a);


#endif
