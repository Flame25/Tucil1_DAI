#include "cube.hpp"
#include <steep_ascent.hpp>

void steep_ascent::hill_climbing() {
  bool found = false;
  int currentErr = cube::objective_func();

  cube::errInfo minVal;
  minVal.error = INT_MAX;
  minVal.x = 9999;
  minVal.y = 9999;
  minVal.z = 9999;

  // Loop trough all elements until finish condition satisfied
  for (int i = 0; i < cube::N; i++) {
    for (int j = 0; j < cube::N; j++) {
      for (int k = 0; k < cube::N; k++) {
        // For each elements
        // Count the error after swapping, then find the smallest one
        cube::errInfo error_note = cube::swap_cube(i, j, k);
        std::cout << error_note.error << " " << std::endl;
        if (minVal.error > error_note.error) {
          minVal = error_note;
          cube::swap(i, j, k, minVal.x, minVal.y, minVal.z);
          std::cout << "Swapped" << std::endl;
          std::cout << "Current Err : " << minVal.error << "/"
                    << cube::objective_func() << std::endl;
        }

        else if (minVal.error <= error_note.error) {
          std::cout << "====Steepest Ascent Finished ====" << std::endl;
          return;
        }
      }
    }
  }
}
