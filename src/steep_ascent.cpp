#include "cube.hpp"
#include <steep_ascent.hpp>

void steep_ascent::hill_climbing() {

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
      cube::swap(targetVal.x, targetVal.y, targetVal.z, neighbor.x, neighbor.y,
                 neighbor.z);
      std::cout << "Current Err : " << neighbor.error << std::endl;
    }

    if (currentErr <= neighbor.error) {
      std::cout << "====Steepest Ascent Finished ====" << std::endl;
      return;
    }
  }
}
