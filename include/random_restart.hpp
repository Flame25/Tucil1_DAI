// #ifndef random_restart_hpp
// #define random_restart_hpp
// #include <cube.hpp>

// namespace random_restart {
// extern int numOfRestart;
// void hill_climbing();
// void setRestartNum(int n);

// } // namespace random_restart

// #endif

#ifndef random_restart_hpp
#define random_restart_hpp
#include <cube.hpp>

namespace random_restart {
extern int numOfRestart;
extern int maxNumOfRestart; // Variabel untuk menyimpan batas maksimum restart
void hill_climbing();
void setRestartParams(int numRestarts, int maxRestarts); // Fungsi untuk mengatur jumlah restart dan batas maksimum

} // namespace random_restart

#endif
