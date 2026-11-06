/**
 * Defines the particle simulation
 */

#include "particle/particle.h"
#include "render/render.h"
#include <stdlib.h>

/**
 * @brief Given a list of particles, it runs the simulation
 *
 * @param particles        particles to simulate
 * @param num_particles    number of particles in the simulation
 * @param time_step        time step to advance
 */
void run_simulation(Particle *particles, size_t num_particles,
                    double time_step);
