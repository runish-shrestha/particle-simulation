#include "particle/particle.h"
#include "raylib.h"
#include "render/render.h"
#include "simulation/simulation.h"
#include "vector/vec.h"
#include <stdlib.h>
#include <time.h>

const int HEIGHT = 1080;
const int WIDTH = 1920;
const int FPS = 60;

double rand_unit(void) { return rand() / (RAND_MAX + 1.0); }

double rand_range(double a, double b) { return a + rand_unit() * (b - a); }

Color rand_color(void) {

  Color random_color = {
      .r = rand_range(0, 255),
      .g = rand_range(0, 255),
      .b = rand_range(0, 255),
  };

  return random_color;
}

Particle *particles_create(size_t num_particles) {

  Particle *particles = malloc(num_particles * sizeof(Particle));

  if (particles == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < num_particles; ++i) {

    particles[i] = Particle_create(
        Vec2_create(rand_range(0, WIDTH), rand_range(0, HEIGHT)),
        Vec2_create(rand_range(-100, 100), rand_range(-100, 100)),
        rand_range(5, 20));
  }

  return particles;
}

Particle_Render_Obj *particle_render_objs_create(size_t num_render_objs) {

  Particle_Render_Obj *render_objs = malloc(num_render_objs * sizeof(Particle_Render_Obj));

  if (render_objs == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < num_render_objs; ++i) {

    render_objs[i] = Particle_Render_Obj_create(rand_color(), rand_color(), rand_range(0.5,1));
  }

  return render_objs;
}

int main(void) {
  srand(time(0));

  InitWindow(WIDTH, HEIGHT, "window");
  SetTargetFPS(FPS);

  size_t particle_count = 10000;
  Particle *particles = particles_create(particle_count);
  Particle_Render_Obj *render_objs = particle_render_objs_create(particle_count);

  run_simulation(particles, render_objs, particle_count, 0.5f / FPS);

  return EXIT_SUCCESS;
}
