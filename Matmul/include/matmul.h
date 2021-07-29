void RandomFloat(float *mat, int row, int col);
void ZeroFloat(float *mat, int row, int col);
void OnesFloat(float *mat, int row, int col, float alpha);
void CustomMatmul(float *A, float *B, float *C, int m, int n, int k);
void NaiveRefMatmul(float *A, float *B, float *C, int m, int n, int k);
void MatrixPrinter(float *mat, int m, int n);
bool CheckEqual(float *C0, float *C1, int m, int n);