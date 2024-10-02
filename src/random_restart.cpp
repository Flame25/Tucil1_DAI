#include "cube.hpp"
#include <random_restart.hpp>
#include <unordered_set>

int random_restart::numOfRestart = 0;

void random_restart::setRestartNum(int n) { random_restart::numOfRestart = n; }

void random_restart::copyCube(int (*first)[5][5], int (*target)[5][5]) {

  std::cout << "Copying Cube" << std::endl;
  for (int i = 0; i < cube::N; i++) {
    for (int j = 0; j < cube::N; j++) {
      for (int k = 0; k < cube::N; k++) {
        target[i][j][k] = first[i][j][k];
      }
    }
  }
}

void random_restart::restart_cube() {
  std::unordered_set<int> existingValues;
  cube::initCube(existingValues);
}

void random_restart::hill_climbing() {

  // Set restart to 2
  setRestartNum(2);

  int bestCube[cube::N][cube::N][cube::N];
  int bestCubeErr = 9999;
  int noteScore[numOfRestart];

  for (int r = 0; r < numOfRestart; r++) {

    while (true) {
      cube::errInfo neighbor;
      cube::errInfo targetVal;

      int currentErr = cube::objective_func();
      // Loop trough all elements until finish condition satisfied
      for (int i = 0; i < cube::N; i++) {
        for (int j = 0; j < cube::N; j++) {
          for (int k = 0; k < cube::N; k++) {
            // For each elements
            // Count the error after swapping, then find the smallest one
            cube::errInfo temp = cube::swap_cube(i, j, k);
            if (neighbor.error > temp.error) {
              neighbor.error = temp.error;
              neighbor.x = temp.x;
              neighbor.y = temp.y;
              neighbor.z = temp.z;

              // Which Element to be swapped
              targetVal.x = i;
              targetVal.y = j;
              targetVal.z = k;
            }
          }
        }
      }

      if (neighbor.error < currentErr) {
        std::cout << "Swapped" << std::endl;
        cube::swap(targetVal.x, targetVal.y, targetVal.z, neighbor.x,
                   neighbor.y, neighbor.z);
        std::cout << "Current Err : " << neighbor.error << std::endl;
      }

      if (currentErr <= neighbor.error) {
        std::cout << "====Hill Climbing Finished ====" << std::endl;
        break;
      }
    }
    // Find best Cube
    noteScore[r] = cube::objective_func();
    if (bestCubeErr > noteScore[r]) {
      bestCubeErr = noteScore[r];
      copyCube(cube::cube, bestCube);
    }
    restart_cube();
  }

  copyCube(bestCube, cube::cube);

  for (int r = 0; r < numOfRestart; r++) {
    std::cout << "Score " << r << " :" << noteScore[r] << std::endl;
  }
  std::cout << "Now Score :" << cube::objective_func() << std::endl;
  std::cout << "===== Random Restart Done =====" << std::endl;
}
