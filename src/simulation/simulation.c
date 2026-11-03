#include "simulation/simulation.h"
#include "particle/particle.h"
#include <raylib.h>

void run_simulation(Particle *particles, size_t num_particles, double time_step) {

  while (!WindowShouldClose()) {

    for (size_t i = 0; i < num_particles; i++) {
      Particle_drift(&particles[i], time_step);
    }

    BeginDrawing();

    ClearBackground(BLACK);
    for (size_t i = 0; i < num_particles; i++) {
      Particle_draw(&particles[i]);

    }
    EndDrawing();
  }
}
