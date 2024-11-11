#include "cube.hpp"
#include <steep_ascent.hpp>

void steep_ascent::hill_climbing() {
  
  while (true) {

    cube::errInfo neighbor;
    cube::errInfo targetVal;

    int currentErr = cube::objective_func();

    for (int i = 0; i < cube::N; i++) {
      for (int j = 0; j < cube::N; j++) {
        for (int k = 0; k < cube::N; k++) {
          cube::errInfo temp = cube::swap_cube(i, j, k);
          if (neighbor.error > temp.error) {
            neighbor.error = temp.error;
            neighbor.x = temp.x;
            neighbor.y = temp.y;
            neighbor.z = temp.z;

            targetVal.x = i;
            targetVal.y = j;
            targetVal.z = k;
          }
        }
      }
    }

    if (neighbor.error < currentErr) {
      cube::swap(targetVal.x, targetVal.y, targetVal.z, neighbor.x, neighbor.y, neighbor.z);
    }

    if (currentErr <= neighbor.error) {
      std::cout << "==== Steepest Ascent Finished ====" << std::endl;
      return;
    }
  }
}
