#include <stdio.h>
#include <math.h>

// ** A: Use a pointer which is pointed to another pointer to pass an 2-diminsional array
// about pointer to pointer: refer to http://www.cnblogs.com/chenbin7/archive/2011/10/03/2198675.html

void PrintMatrix(float** A, int m, int n);
float LargestElement(float** A, int m, int n);
int IsDiagonal(float** A, int n);
float Transpose(float** A, float** B, int m, int n);
// assignment 1
void MatrixMultiply(float** A, float** B, float** C, int m, int n, int p);

int main(int argc, char* argv[])
{
    // A[m][n]:
    // x11, x12, ..., x1n
    // x21, x22, ..., x2n
    // ..., ..., ..., ...
    // xm1, xm2, ..., xmn

    // define A
    float A[2][2] = {{114, 514}, {1919, 810}};
    float B[2][2] = {{38, 324}, {14, 122}};
    float C[2][2];
    float D[2][2];

    // float *pA[2] is an array of pointers
    // float (*pA)[2] is a pointer to an array
    // in {A[0], A[1]}, A[0] and A[1] are pointers 
    float *pA[2] = {A[0], A[1]};
    float *pB[2] = {B[0], B[1]};
    float *pC[2] = {C[0], C[1]};
    float *pD[2] = {D[0], D[1]};

    // **ppA is a pointer to pA, so ppA is a pointer to another pointer
    float **ppA = pA;
    float **ppB = pB;
    float **ppC = pC;
    float **ppD = pD;

    printf("Matrix A: \n");
    PrintMatrix(ppA, 2, 2);
    printf("Matrix B: \n");
    PrintMatrix(ppB, 2, 2);
    printf("Largest element of A: %f\n", LargestElement(ppA, 2, 2));
    printf("A is diagonal: %d\n", IsDiagonal(ppA, 2));
    printf("Transpose of A: \n");
    Transpose(ppA, ppC, 2, 2);
    PrintMatrix(ppC, 2, 2);
    printf("Multiply A and B: \n");
    MatrixMultiply(ppA, ppB, ppD, 2, 2, 2);
    PrintMatrix(ppD, 2, 2);

}

void PrintMatrix(float** A, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        printf("[");
        for (int j = 0; j < n - 1; j++)
        {
            printf("%f, ", A[i][j]);
        }
        printf("%f]\n", A[i][n-1]);
    }
}

float LargestElement(float** A, int m, int n)
{
    float max = A[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] > max)
            {
                max = A[i][j];
            }
        }
    }
    return max;
}

int IsDiagonal(float** A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i][j] != 0 || A[j][i] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

float Transpose(float** A, float** B, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[j][i] = A[i][j];
        }
    }
    return 0;
}

void MatrixMultiply(float** A, float** B, float** C, int m, int n, int p){
    // Will update after assignment 1 due
    for (int ci = 0; ci < p; ci += 1)
    {
        for (int cj = 0; cj < m; cj += 1)
        {
            float sum = 0;
            for (int i = 0; i < n; i += 1) 
            {
                sum += A[ci][i] * B[i][cj];
            }
            C[ci][cj] = sum;
        }
    }
    return;
}