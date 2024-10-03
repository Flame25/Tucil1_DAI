#include "simulated_annealing.hpp"
#include "stochastic.hpp"
#include <cube.hpp>
#include <genetic_algorithm.hpp>
#include <open_gl_utils.hpp>
#include <random_restart.hpp>
#include <side_ways.hpp>
#include <steep_ascent.hpp>
#include <string>

void userInput() {
  std::cout << "==== Welcome ====" << "\n"
            << "Benchmarking started" << std::endl;
  int score_benchmark[6];
  int cube_benchmark[cube::N][cube::N][cube::N];
  cube::copyCube(cube::cube, cube_benchmark);
  // Calculate the duration
  std::chrono::duration<double> elapsed[6];

  auto start = std::chrono::steady_clock::now();
  steep_ascent::hill_climbing();
  auto end = std::chrono::steady_clock::now();
  score_benchmark[0] = cube::objective_func();
  elapsed[0] = end - start;
  cube::copyCube(cube_benchmark, cube::cube);

  start = std::chrono::steady_clock::now();
  simulated_annealing::work_func();
  end = std::chrono::steady_clock::now();
  score_benchmark[1] = cube::objective_func();
  elapsed[1] = end - start;
  cube::copyCube(cube_benchmark, cube::cube);

  start = std::chrono::steady_clock::now();
  side_ways::hill_climbing();
  end = std::chrono::steady_clock::now();
  score_benchmark[2] = cube::objective_func();
  elapsed[2] = end - start;
  cube::copyCube(cube_benchmark, cube::cube);

  start = std::chrono::steady_clock::now();
  stochastic::hill_climbing();
  end = std::chrono::steady_clock::now();
  score_benchmark[3] = cube::objective_func();
  elapsed[3] = end - start;
  cube::copyCube(cube_benchmark, cube::cube);

  start = std::chrono::steady_clock::now();
  genetic_algorithm::work_func();
  end = std::chrono::steady_clock::now();
  score_benchmark[4] = cube::objective_func();
  elapsed[4] = end - start;
  cube::copyCube(cube_benchmark, cube::cube);

  start = std::chrono::steady_clock::now();
  random_restart::hill_climbing();
  end = std::chrono::steady_clock::now();
  score_benchmark[5] = cube::objective_func();
  elapsed[5] = end - start;
  cube::copyCube(cube_benchmark, cube::cube);

  std::string algo[6] = {"Steepest Ascent",   "Simulated Annealing",
                         "Side Ways",         "Stochastic",
                         "Genetic algorithm", "Random Restart"};
  std::cout << "==== Benchmarking Results ====" << std::endl;
  for (int i = 0; i < 6; i++) {
    std::cout << i + 1 << ". " << algo[i] << " >> Time : " << elapsed[i].count()
              << " seconds " << " >> Score : " << score_benchmark[i]
              << std::endl;
  }
}
int main(int argc, char **argv) {
  std::srand(
      static_cast<unsigned int>(std::time(nullptr))); // Seed for randomness

  // Initialize GLUT
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Magic Cube 5x5x5");

  // Initialize OpenGL settings and cube data
  open_gl_utils::init();

  // Register callback functions
  glutDisplayFunc(open_gl_utils::display);
  glutReshapeFunc(open_gl_utils::reshape);
  glutMouseFunc(
      open_gl_utils::mouseButton); // Register mouse button event handler
  glutMotionFunc(
      open_gl_utils::mouseMotion);    // Register mouse motion event handler
  std::thread cubeUpdater(userInput); // Different thread
  // for
  //  updating cube

  // Enter the main loop
  glutMainLoop();

  cubeUpdater.join(); // Wait for the updateCube thread to finish before
  // exiting
  return 0;
}
