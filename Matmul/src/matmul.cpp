#include "matmul.h"

#include <string.h>

#include <cstdlib>
#include <iostream>

#define alpha( i,j,lD ) A[ (j)*lD + (i) ]   // map alpha( i,j ) to array A
#define beta( i,j,lD )  B[ (j)*lD + (i) ]   // map beta( i,j ) to array B
#define gamma( i,j,lD ) C[ (j)*lD + (i) ]   // map gamma( i,j ) to array C

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
  memset(matrix, 0, row * col * sizeof(float));
}

void OnesFloat(float *matrix, int row, int col, float alpha = 1.0) {
  const int kSize = row*col;
  for(int i = 0; i <kSize; i++) {
    matrix[i] = alpha;
  }
}

void CustomMatmul(float *A, float *B, float *C, int m, int n, int k) { return; }

void NaiveRefMatmul(float *A, float *B, float *C, int m, int n, int k) {
  for(int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int p = 0; p < n; p++) {
        gamma(i,j,m) += alpha(i,p,m) * beta(p,j,k);
      }
    }
  }
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