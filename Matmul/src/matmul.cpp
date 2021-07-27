#include "matmul.h"

#include <string.h>

#include <cstdlib>
#include <iostream>

void RandomFloat(float *matrix, int row, int col) {
  int num_dim = row * col;
  float max_float = 100.0;
  for (int ind = 0; ind < num_dim; ind++) {
    float rnd_num =
        static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / max_float));
    *(matrix + ind) = rnd_num;
  }
}

void ZeroFloat(float *matrix, int row, int col) {
  memset(matrix, 0, row * col);
}

void CustomMatmul(float *A, float *B, float *C, int m, int n, int k) { return; }

void NaiveRefMatmul(float *A, float *B, float *C, int m, int n, int k) {
  return;
}

void MatrixPrinter(float *A, int m, int n) {
  const int kSize = m * n;
  for (int i = 0; i < kSize; i++) {
    int y = i % n;
    int x = i / n;
    std::cout << *(A + y * m + x) << ",";
    if (((i + 1) % n) == 0) std::cout << "\n";
  }
  std::cout << "\n";
}

bool CheckEqual(float *C0, float *C1, int m, int n) {
  const int kSize = m * n;
  for (int i = 0; i < kSize; i++) {
    if (*(C0 + i) != *(C1 + i)) return false;
  }
  return true;
}