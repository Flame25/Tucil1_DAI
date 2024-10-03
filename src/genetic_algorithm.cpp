#include "cube.hpp"
#include <algorithm>
#include <cstdlib>
#include <genetic_algorithm.hpp>
#include <set>
#include <vector>

int population_num = 2;
int N = 5;
double MUTATION_PROB = 0.05;
// Function to perform Cycle Crossover on a 2D array (one layer of the 3D array)
void genetic_algorithm::cycleCrossover2D(int parent1Layer[cube::N][cube::N],
                                         int parent2Layer[cube::N][cube::N],
                                         int offspringLayer[cube::N][cube::N]) {
  bool visited[cube::N][cube::N] = {false}; // To track visited elements

  // Cycle Crossover for 2D array
  for (int start = 0; start < N * N; ++start) {
    int row = start / N;
    int col = start % N;

    if (!visited[row][col]) {
      int current = start;
      do {
        row = current / N;
        col = current % N;

        // Copy element from parent1 to offspring
        offspringLayer[row][col] = parent1Layer[row][col];
        visited[row][col] = true;

        // Find the next element in the cycle (from parent2 to parent1)
        int nextElem = parent2Layer[row][col];

        // Search for the element in parent1
        bool found = false;
        for (int r = 0; r < N && !found; ++r) {
          for (int c = 0; c < N && !found; ++c) {
            if (parent1Layer[r][c] == nextElem) {
              current = r * N + c;
              found = true;
            }
          }
        }

      } while (current != start); // Cycle ends when we reach the start index
    }
  }
}

// Function to apply mutation based on a probability
void genetic_algorithm::applyMutation(int offspring[cube::N][cube::N][cube::N],
                                      int allowedValues[], int allowedSize) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        // Randomly mutate based on mutation probability
        if ((double)rand() / RAND_MAX < MUTATION_PROB) {
          // Select a random element from allowedValues (ensure no duplicates)
          int newVal;
          bool duplicate;
          do {
            newVal = allowedValues[rand() % allowedSize];
            duplicate = false;
            // Check for duplicates in the current layer
            for (int l = 0; l < N; ++l) {
              if (offspring[i][j][l] == newVal) {
                duplicate = true;
                break;
              }
            }
          } while (duplicate);

          offspring[i][j][k] = newVal; // Mutate the element
        }
      }
    }
  }
}

// Cycle Crossover for 3D arrays with mutation
void genetic_algorithm::cycleCrossoverWithMutation(
    int parent1[cube::N][cube::N][cube::N],
    int parent2[cube::N][cube::N][cube::N],
    int offspring[cube::N][cube::N][cube::N], int allowedValues[],
    int allowedSize) {
  // Apply cycle crossover layer by layer (for each 2D array in the 3D cube)
  for (int i = 0; i < N; ++i) {
    cycleCrossover2D(parent1[i], parent2[i], offspring[i]);
  }

  // Apply mutation after crossover
  applyMutation(offspring, allowedValues, allowedSize);
}
void genetic_algorithm::work_func() {
  std::set<int> new_population;
  int population_num = 2;

  std::vector<genetic_algorithm::individual> population;

  // Current generation
  int generation = 0;

  // Create randomized initial cube
  for (int i = 0; i < population_num; i++) {
    individual new_cube;
    new_cube.fitness = cube::objective_func();
    cube::copyCube(cube::cube, new_cube.cube);
    population.push_back(new_cube);
    cube::restart_cube();
  }

  // Start main looping
  // Do roullete n times, cross over
  for (int i = 0; i < 1000000; i++) {

    int probabilities[population_num];
    int all_score[population_num];

    for (int i = 0; i < population_num; i++) {
      int sum = 0;
      for (int j = 0; j < population_num; j++) {
        sum += all_score[j];
      }
      probabilities[i] = (all_score[i] / sum) * 100;
    }

    int count = 0;
    int roullete[110]; // Extra in case the probabilities not 100% because of
                       // roundings
    for (int i = 0; i < population_num; i++) {
      for (int j = 0; j < probabilities[i]; j++) {
        roullete[count + j] = i;
      }
      count += probabilities[i];
    }

    int choosen_parent[population_num];
    for (int i = 0; i < population_num; i++) {
      choosen_parent[i] = roullete[random() % population_num];
    }

    // if the individual having lowest fitness score ie.
    // 0 then we know that we have reached to the target
    // and break the loop
    if (population[0].fitness <= 0) {
      break;
    }

    int allowedValues[N * N * N];
    for (int i = 0; i < N * N * N; ++i) {
      allowedValues[i] = i + 1;
    }
    int allowedSize = N * N * N;

    for (int i = 0; i < population_num / 2; i++) {

      // Offspring array
      int offspring[cube::N][cube::N][cube::N] = {{{0}}}; // Initialize with 0s
      // Perform cycle crossover with mutation
      cycleCrossoverWithMutation(population[choosen_parent[i]].cube,
                                 population[choosen_parent[i + 1]].cube,
                                 offspring, allowedValues, allowedSize);
      int num = cube::objective_func(offspring);
      individual new_one;
      new_one.fitness = num;
      cube::copyCube(offspring, new_one.cube);
      population.push_back(new_one);
    }

    std::cout << "Generation: " << generation << "\t" << std::endl;

    generation++;
  }

  individual smallestOne;
  smallestOne.fitness = 9999;
  std::cout << "Current Err :" << cube::objective_func() << std::endl;
  for (individual i : population) {
    if (i.fitness < smallestOne.fitness) {
      smallestOne = i;
    }
  }

  std::cout << "New Err :" << smallestOne.fitness << std::endl;
}
