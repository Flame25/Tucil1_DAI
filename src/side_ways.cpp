#include "cube.hpp"
#include <side_ways.hpp>

void side_ways::hill_climbing() {
  const int max_sideways_moves = 100;  // Batas maksimum sideways move
  int sideways_moves = 0;              // Counter untuk sideways move
  int total_moves = 0;                 // Counter untuk total langkah (iterasi) yang dilakukan

  while (true) {

    cube::errInfo neighbor;
    cube::errInfo targetVal;
    int currentErr = cube::objective_func(); 

    // Mencari neighbor dengan error terkecil
    for (int i = 0; i < cube::N; i++) {
      for (int j = 0; j < cube::N; j++) {
        for (int k = 0; k < cube::N; k++) {
          cube::errInfo temp = cube::swap_cube(i, j, k);
          if (neighbor.error > temp.error || (neighbor.error == currentErr && temp.error == currentErr)) {
            neighbor.error = temp.error;
            neighbor.x = temp.x;
            neighbor.y = temp.y;
            neighbor.z = temp.z;

            targetVal.x = i;
            targetVal.y = j;
            targetVal.z = k;
          }
        }
      }
    }

    // Tambah hitungan total langkah (total_moves)
    total_moves++;

    // Jika terjadi sideways move (nilai error current state == neighbor), tambahkan sideways_moves
    if (neighbor.error == currentErr) {
      sideways_moves++;  // Tambah hitungan sideways move
    }

    // Lakukan pertukaran jika ada neighbor yang sama atau lebih baik
    if (neighbor.error <= currentErr) {
      cube::swap(targetVal.x, targetVal.y, targetVal.z, neighbor.x, neighbor.y, neighbor.z);
      currentErr = neighbor.error;  // Update currentErr dengan error terbaru setelah swap
    }

    // Cek kondisi terminasi
    if (neighbor.error > currentErr || sideways_moves >= max_sideways_moves) {
      if (sideways_moves >= max_sideways_moves) {
        std::cout << "==== Pencarian Sideways Move dihentikan karena mencapai Sideways Move Maksimum====" << std::endl;
      } else {
        std::cout << "==== Pencarian Sideways dihentikan karena mancapai local/global optima ====" << std::endl;
        std::cout << "==Algoritma diterminasi pada iterasi sideways move ke: " << sideways_moves <<"=="<<std::endl;
      }
      return;
    }
  }
}

