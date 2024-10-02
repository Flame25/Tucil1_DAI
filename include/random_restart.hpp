#include <cube.hpp>

namespace random_restart {
extern int numOfRestart;
void hill_climbing();
void setRestartNum(int n);

// Re-initialized cube with random value
void restart_cube();

// Copy Cube function
void copyCube(int first[cube::N][cube::N][cube::N],
              int target[cube::N][cube::N][cube::N]);

} // namespace random_restart
