#ifndef cube_hpp
#define cube_hpp

#include <climits>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_set>
#include <vector>

namespace cube {

struct errInfo {
  int error = 0;
  int x, y, z;
};
const int num_neighbors = 10; // Number of neighbors to generate
const int N = 5;              // Cube size (5x5x5)
extern int cube[N][N][N];     // 3D array to represent the cube

// Display per Layer of Cube via CMD
void displayCube();

// Initialize the cube with unique and random values (1 to N^5)
void initCube(std::unordered_set<int> existingValues);

// Cube Objective Function
int objective_func();

// Swap position of element in cube
void swap(int x1, int y1, int z1, int x2, int y2, int z2);

// Cube Swapping System to check error
// Works by check all possible condition which one is the best
// All possible condition = Horizontal, Vertical, Pillar Axis Movement
errInfo swap_cube(int x, int y, int z);

// Min Value getter special for errInfo based on Error Only
errInfo minVal(std::vector<errInfo> vec);

// Helper function to add absolute differences from 315 to total_sum
int calculate(const std::vector<int> &sums, int target);

// Helper function to reset sums to zero
void resetSums(std::vector<int> &sums);

} // namespace cube

#endif
