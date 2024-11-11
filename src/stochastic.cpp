#include "cube.hpp"
#include <cstdlib>
#include <stochastic.hpp>

int stochastic::max_iteration = 5000;
void stochastic::setMaxIter(int n) { max_iteration = n; }

// Randomizer works by taking some 10 random swap and choose best
void stochastic::random_swap() {
  // Seed the random number generator with the current time
  cube::errInfo bestData;
  bestData.error = cube::objective_func();
  bool improved = false;
  cube::errInfo target;
  for (int r = 0; r < 100; r++) {
    //  Generate a random number between 0 and 124
    int i_1 = std::rand() % 5; // 125 gives a range of 0-124
    int j_1 = std::rand() % 5;
    int k_1 = std::rand() % 5;

    int i_2 = std::rand() % 5;
    int j_2 = std::rand() % 5;
    int k_2 = std::rand() % 5;

    cube::swap(i_1, j_1, k_1, i_2, j_2, k_2);
    int currentErr = cube::objective_func();
    if (bestData.error > currentErr) {
      bestData.error = currentErr;
      bestData.x = i_1;
      bestData.y = j_1;
      bestData.z = k_1;

      target.x = i_2;
      target.y = j_2;
      target.z = k_2;
      improved = true;
    }
    cube::swap(i_1, j_1, k_1, i_2, j_2, k_2);
  }

  // std::cout << bestData.x << " " << bestData.y << " " << bestData.z << " "
  //          << target.x << " " << target.y << " " << target.z << std::endl;
  if (improved)
    cube::swap(bestData.x, bestData.y, bestData.z, target.x, target.y,
               target.z);
}
void stochastic::hill_climbing() {
  setMaxIter(10000);
  for (int i = 0; i < max_iteration; i++) {
    random_swap();
  }
  std::cout << "Final Error : " << cube::objective_func() << "\n"
            << "===== Stochastic Hill Climbing Done =====" << std::endl;
}
