#ifndef genetic_algorithm_hpp
#define genetic_algorithm_hpp

#include <cube.hpp>

namespace genetic_algorithm {
struct individual {
  int cube[cube::N][cube::N][cube::N];
  int fitness = 999;
};
void work_func();

void crossover(int cube1[cube::N][cube::N][cube::N],
               int cube2[cube::N][cube::N][cube::N],
               int cube_target[cube::N][cube::N][cube::N]);

void cycleCrossoverWithMutation(int parent1[cube::N][cube::N][cube::N],
                                int parent2[cube::N][cube::N][cube::N],
                                int offspring[cube::N][cube::N][cube::N],
                                int allowedValues[], int allowedSize);

void cycleCrossover2D(int parent1Layer[cube::N][cube::N],
                      int parent2Layer[cube::N][cube::N],
                      int offspringLayer[cube::N][cube::N]);

void applyMutation(int offspring[cube::N][cube::N][cube::N],
                   int allowedValues[], int allowedSize);
} // namespace genetic_algorithm

#endif
