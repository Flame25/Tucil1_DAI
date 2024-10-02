#include <climits>
#include <cstdlib>
#include <cube.hpp>
#include <ostream>
#include <vector>

int cube::cube[cube::N][cube::N][cube::N]; // Definition and initialization

// Display per Layer of Cube via CMD
void cube::displayCube() {
  for (int i = 0; i < N; ++i) {
    std::cout << "Layer " << i + 1 << ":\n";
    for (int j = N - 1; j >= 0; --j) {
      for (int k = 0; k < N; ++k) {
        std::cout << cube[i][j][k] << " ";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
  // INFO:Somehow cannot display text after loop finished -> Forget to add
  // std::endl

  std::cout << "==== Error ====" << std::endl;
  std::cout << objective_func() << std::endl;
}

// Initialize the cube with unique and random values (1 to N^5)
void cube::initCube(std::unordered_set<int> existingValues) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        int randomValue;
        do {
          randomValue =
              rand() % 125 + 1; // Generates a number between 1 and 125
        } while (existingValues.find(randomValue) !=
                 existingValues.end()); // Ensure uniqueness

        // Add the value to the set of existing values
        existingValues.insert(randomValue);

        // Assign the unique value to the cube at position (i, j, k)
        cube[i][j][k] = randomValue;
      }
    }
  }
  displayCube();
}

// Helper function to reset sums to zero
void cube::resetSums(std::vector<int> &sums) {
  std::fill(sums.begin(), sums.end(), 0);
}

// Helper function to add absolute differences from 315 to total_sum
int cube::calculate(const std::vector<int> &sums, int target) {
  int total_diff = 0;
  for (int sum : sums) {
    if (sum != 0)
      total_diff += (sum != 315);
  }
  return total_diff;
}

// Cube Objective Function
int cube::objective_func() {
  int total_sum = 0;
  std::vector<int> sums(6, 0); // For storing sum1 to sum6
  const int target_sum = 315;

  // Horizontal, Vertical, Pillar
  for (int i = 0; i < cube::N; i++) {
    for (int j = 0; j < cube::N; j++) {
      for (int k = 0; k < cube::N; k++) {
        sums[0] += cube[i][j][k];
        sums[1] += cube[k][i][j];
        sums[2] += cube[i][k][j];
      }
      total_sum += calculate(sums, target_sum);
      resetSums(sums);
    }
  }

  // Space Diagonal
  for (int i = 0; i < cube::N; i++) {
    sums[0] = cube[i][i][i];
    sums[1] = cube[5 - i][i][i];
    sums[2] = cube[5 - i][5 - i][5 - i];
    sums[3] = cube[i][5 - i][5 - i];
  }
  total_sum += calculate(sums, target_sum);
  resetSums(sums);

  // Plane Diagonal
  for (int i = 0; i < cube::N; i++) {
    for (int j = 0; j < cube::N; j++) {
      sums[0] += cube[i][j][j];
      sums[1] += cube[j][i][j];
      sums[2] += cube[j][j][i];
      sums[3] += cube[5 - j][5 - j][i];
      sums[4] += cube[i][5 - j][5 - j];
      sums[5] += cube[5 - j][i][5 - j];
    }
    total_sum += calculate(sums, target_sum);
    resetSums(sums);
  }

  return total_sum;
}

void cube::swap(int x1, int y1, int z1, int x2, int y2, int z2) {
  int temp = cube::cube[x1][y1][z1];
  cube::cube[x1][y1][z1] = cube::cube[x2][y2][z2];
  cube::cube[x2][y2][z2] = temp;
}

// Min Val special for errInfo only based on error
cube::errInfo cube::minVal(std::vector<cube::errInfo> vec) {
  errInfo minVal;
  minVal.error = INT_MAX;
  minVal.x = 9999;
  minVal.y = 9999;
  minVal.z = 9999;
  for (int i = 0; i < vec.size(); i++) {
    if (minVal.error > vec[i].error) {
      minVal = vec[i];
    }
  }
  return minVal;
}

// Implement by check all the possible movement first
// Then, check the lowest error and change cube to that position
cube::errInfo cube::swap_cube(int x, int y, int z) {
  std::vector<cube::errInfo> error_list;
  // for (int i = 0; i < cube::N; i++) {

  //   // For Z axis only
  //   swap(x, y, z, i, y, z);
  //   cube::errInfo noted_error;
  //   noted_error.error = objective_func();
  //   noted_error.x = i;
  //   noted_error.y = y;
  //   noted_error.z = z;

  //   error_list.insert(error_list.begin(), noted_error);

  //   // Revert back condition
  //   swap(x, y, z, i, y, z);

  //   // For Y Axis Only
  //   swap(x, y, z, x, i, z);
  //   noted_error.error = objective_func();
  //   noted_error.x = x;
  //   noted_error.y = i;
  //   noted_error.z = z;

  //   error_list.insert(error_list.begin(), noted_error);

  //   swap(x, y, z, x, i, z);

  //   // For Z Axis only
  //   swap(x, y, z, x, y, i);
  //   noted_error.error = objective_func();
  //   noted_error.x = x;
  //   noted_error.y = y;
  //   noted_error.z = i;

  //   error_list.insert(error_list.begin(), noted_error);

  //   swap(x, y, z, x, y, i);
  // }

  // Try All Possible Places
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {

        swap(x, y, z, i, j, k);
        cube::errInfo noted_error;
        noted_error.error = objective_func();
        noted_error.x = i;
        noted_error.y = j;
        noted_error.z = k;

        error_list.insert(error_list.begin(), noted_error);

        swap(x, y, z, i, j, k);
      }
    }
  }
  return minVal(error_list);
}
