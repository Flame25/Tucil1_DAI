#include "cube.hpp"
#include "matplotlibcpp.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <steep_ascent.hpp>
#include <vector>

void steep_ascent::hill_climbing() {
  int count = 0;

  if (std::remove("steepascent.txt") == 0) {
    std::cout << "steepAscent.txt was deleted successfully.\n";
  } else {
    std::cout << "steepAscent.txt did not exist or couldn't be deleted.\n";
  }

  std::ofstream result("steepascent.txt", std::ios::app);
  if (!result) {
    std::cerr << "Error opening steepAscent.txt for writing." << std::endl;
    return;
  }

  if (std::remove("swap.txt") == 0) {
    std::cout << "swap.txt was deleted successfully.\n";
  } else {
    std::cout << "swap.txt did not exist or couldn't be deleted.\n";
  }

  // Open swap.txt in append mode for writing scores
  std::ofstream file("swap.txt", std::ios::app);
  if (!file) {
    std::cerr << "Error opening swap.txt for writing." << std::endl;
    return;
  }

  while (true) {

    cube::errInfo neighbor;
    cube::errInfo targetVal;

    int currentErr = cube::objective_func();
    count++;

    if (!file) {
      std::cerr << "Error opening file." << std::endl;
      return;
    }

    file << currentErr << ";";

    // Loop through all elements until finish condition satisfied
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
      // std::cout << "Swapped" << std::endl;
      cube::swap(targetVal.x, targetVal.y, targetVal.z, neighbor.x, neighbor.y,
                 neighbor.z);
      // std::cout << "Current Err : " << neighbor.error << std::endl;
    }

    if (currentErr <= neighbor.error) {
      std::cout << "====Steepest Ascent Finished ====" << std::endl;

      file.close();

      // Read the content from swap.txt and prepend a new line in
      // steepAscent.txt
      std::ifstream read_file("swap.txt");
      if (!read_file) {
        std::cerr << "Error opening swap.txt for reading." << std::endl;
        return;
      }

      std::stringstream buffer;
      buffer << read_file.rdbuf();

      std::cout << "Hello : " << buffer.str() << std::endl;
      read_file.close();

      result << count << std::endl;
      result << buffer.str();
      result.close();
      return;
    }
  }
}
