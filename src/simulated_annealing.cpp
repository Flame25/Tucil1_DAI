#include "cube.hpp"
#include <cmath>
#include <simulated_annealing.hpp>

double simulated_annealing::alpha = 0.9;
void setAlpha(int n) { simulated_annealing::alpha = n; }
void simulated_annealing::work_func() {
  int currentErr = cube::objective_func();
  double T = 9999.0;
  while (true) {
    if (T <= 0.00000001) {
      break;
    }

    cube::errInfo bestData;
    bool improved = false;
    cube::errInfo target;
    // Choose best candidate between all candidates
    for (int r = 0; r < 1000; r++) {
      //  Generate a random number between 0 and 124
      int i_1 = std::rand() % 5; // 125 gives a range of 0-124
      int j_1 = std::rand() % 5;
      int k_1 = std::rand() % 5;

      int i_2 = std::rand() % 5;
      int j_2 = std::rand() % 5;
      int k_2 = std::rand() % 5;

      cube::swap(i_1, j_1, k_1, i_2, j_2, k_2);
      int swapErr = cube::objective_func();
      if (bestData.error > swapErr) {
        bestData.error = swapErr;
        bestData.x = i_1;
        bestData.y = j_1;
        bestData.z = k_1;

        target.x = i_2;
        target.y = j_2;
        target.z = k_2;
      }
      cube::swap(i_1, j_1, k_1, i_2, j_2, k_2);
    }
    // Count Probs for choosing bad
    double ap = exp((bestData.error - currentErr) / T);
    T *= alpha;

    // std::cout << bestData.x << " " << bestData.y << " " << bestData.z << " "
    //          << target.x << " " << target.y << " " << target.z << std::endl;

    // std::cout << "Selected : " << currentErr << "/" << bestData.error
    //          << std::endl;
    if (bestData.error < currentErr) {
      cube::swap(bestData.x, bestData.y, bestData.z, target.x, target.y,
                 target.z);
    } else if (ap > (double)rand() / RAND_MAX) {
      // std::cout << "Bad Selected : " << currentErr << "/" << bestData.error
      //<< std::endl;
      cube::swap(bestData.x, bestData.y, bestData.z, target.x, target.y,
                 target.z);
    }
  }
  std::cout << " ==== Simulated Annealing Finished ===== " << "\n"
            << "Final Error : " << cube::objective_func() << std::endl;
}
