#include "cube.hpp"
#include <algorithm>
#include <cstdlib>
#include <genetic_algorithm.hpp>
#include <set>
#include <vector>
#include <random>
#include <numeric>

int population_num = 4;
int N = 5;
double MUTATION_PROB = 0.20;

//FUNCTION FOR CROSSOVER 
void genetic_algorithm::crossover(int parent1[cube::N][cube::N][cube::N],
                                  int parent2[cube::N][cube::N][cube::N],
                                  int cube_target1[cube::N][cube::N][cube::N],
                                  int cube_target2[cube::N][cube::N][cube::N]){
  std::vector<int> flatcube1;
  std::vector<int> flatcube2;

  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      for (int k = 0; k < N; ++k){
        flatcube1.push_back(parent1[i][j][k]);
      }
    }
  }

  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j){
      for (int k = 0; k < N; ++k){
        flatcube2.push_back(parent2[i][j][k]);
      }
    }
  }
  
  int length = flatcube1.size();
  bool visited[cube::N] = {false};

  

}
// Function to perform Cycle Crossover on a 2D array (one layer of the 3D array)
void genetic_algorithm::cycleCrossover2D(int parent1Layer[cube::N][cube::N],
                                         int parent2Layer[cube::N][cube::N],
                                         int offspringLayer[cube::N][cube::N]) {
  bool visited[cube::N][cube::N] = {false}; // To track visited elements

  // Cycle Crossover for 2D array
  for (int start = 0; start < N * N; ++start) {
    std::cout<<"Masuk loop"<<std::endl;
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
              std::cout<<"selesailoop"<<std::endl;
            }
          }
        }

      } while (current != start); // Cycle ends when we reach the start index
    }
  }
  std::cout<<"finish2D"<<std::endl;
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
    std::cout<<"masuk"<<i<<std::endl;
    cycleCrossover2D(parent1[i], parent2[i], offspring[i]);
  }

  // Apply mutation after crossover
  applyMutation(offspring, allowedValues, allowedSize);
}

void genetic_algorithm::work_func() {
  std::set<int> new_population;
  // int population_num = 10;

  std::vector<genetic_algorithm::individual> population;

  // Current generation
  int generation = 0;

  // Create randomized initial cube
  for (int i = 0; i < population_num; i++) {
    individual new_cube;
    new_cube.fitness = 110 - cube::objective_func(); //Lower objective function value mean better fitness so we inverse
    cube::copyCube(cube::cube, new_cube.cube);
    population.push_back(new_cube);
    cube::restart_cube();
  }
  std::cout<<"init jalan"<<std::endl; //DEBUG

  // Start main looping
  // Do roullete n times, cross over
  for (int i = 0; i < 10000; i++) {
    // Sort by fitness in descending order
    std::sort(population.begin(), population.end(), [](const genetic_algorithm::individual& a, const genetic_algorithm::individual& b) {
        return a.fitness > b.fitness;
    });
    double probabilities[population_num]; //for relative probability of each individual
    // int all_score[population_num];

    double sum_score = 0;
    for(int i = 0; i < population_num; i++){
      sum_score += population[i].fitness;
    }
    std::cout<<"work1"<<std::endl; //DEBUG
    std::cout<<sum_score<<std::endl;

    for(int i = 0; i < population_num; i++){
      probabilities[i] = population[i].fitness/(sum_score);
    }
    std::cout<<"work2"<<std::endl; //DEBUG
    for(int i = 0; i < population_num; i++){
      std::cout<<probabilities[i]<<std::endl;
    }

    double cummulative_prob = 0;
    for(int i = 0; i < population_num; i++){
      cummulative_prob += probabilities[i];
      population[i].probabilities = cummulative_prob;
    }
    std::cout<<"work3"<<std::endl; //DEBUG
    for(int i = 0; i < population_num; i++){
      std::cout<<population[i].probabilities<<std::endl;
    }
    std::cout<<"uhuy"<<std::endl;
    // int choosen_parent[population_num];
    // for (int i = 0; i < population_num; i++) {
    //   choosen_parent[i] = rand();
    // }

    int allowedValues[N * N * N];
    for (int i = 0; i < N * N * N; ++i) {
      allowedValues[i] = i + 1;
    }
    int allowedSize = N * N * N;

    int firstparent = 0;
    int secondparent = 0;

    for (int i = 0; i < population_num / 2; i++) {
      bool foundfirst = false;
      bool foundsecond = false;
      double r = ((double) rand() / (RAND_MAX)); //rand value (0,1)
      std::cout<<r<<std::endl; //DEBUG
      for(int j = 0; j < population_num; j++){
        if(population[j].probabilities <= r && !foundfirst){ //if found lowerbound
          firstparent = j;
          foundfirst = true;
          std::cout<<"foundfirst"<<j<<std::endl; //DEBUG
        }
      }

      for(int j = 0; j < population_num; j++){
        if(population[j].probabilities >= r && !foundsecond){ //if found upperbound
          secondparent = j;
          std::cout<<"foundsecond"<<j<<std::endl; //DEBUG
          foundsecond = true;
        }
      }

      //TO DO
      std::cout<<population[firstparent].cube<<std::endl;
      std::cout<<population[secondparent].cube<<std::endl;
      std::cout<<"startcrossover"<<std::endl; //DEBUG
      // Offspring array
      int offspring[cube::N][cube::N][cube::N] = {{{0}}}; // Initialize with 0s
      // Perform cycle crossover with mutation
      cycleCrossoverWithMutation(population[firstparent].cube,
                                 population[secondparent].cube,
                                 offspring, allowedValues, allowedSize);
      std::cout<<"crossover finish"<<std::endl; //DEBUG
      int num = cube::objective_func(offspring); 
      individual new_one;
      new_one.fitness = 110 - num; //relative fitness
      cube::copyCube(offspring, new_one.cube);
      population.push_back(new_one);
    }

    std::cout << "Generation: " << generation << "\t" << std::endl;

    generation++;
    population_num = population.size(); //Update population size
  }

  individual smallestOne;
  smallestOne.fitness = 9999;
  // std::cout << "Current Err :" << cube::objective_func() << std::endl;
  for (individual i : population) {
    if (i.fitness < smallestOne.fitness) {
      smallestOne = i;
    }
  }

  // std::cout << "New Err :" << smallestOne.fitness << std::endl;
}
