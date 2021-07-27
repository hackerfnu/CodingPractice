#include "iostream"
#include "matmul.h"

#define M 10
#define N 10
#define K 10
#define ROW 9
#define COL 10

int main() {
  // Let's do matmul of C = A*B;
  float *A, *B, *C, *C_ref;
  A = new float[M * K];
  B = new float[K * N];
  C = new float[M * N];
  C_ref = new float[M * N];
  RandomFloat(A, M, K);
  RandomFloat(B, K, N);
  ZeroFloat(C, M, N);
  std::cout << "Matrix A:\n";
  MatrixPrinter(A, M, K);
  std::cout << "Matrix B:\n";
  MatrixPrinter(B, K, N);
  std::cout << "Matrix C:\n";
  MatrixPrinter(C, M, N);
  CustomMatmul(A, B, C, M, N, K);
  NaiveRefMatmul(A, B, C_ref, M, N, K);
  bool same_result = CheckEqual(C, C_ref, M, N);
  if (!same_result) {
    std::cout << "Wrong Implementation!";
  } else {
    std::cout << "Awesome correct implementation!\n";
  }
  return 0;
}