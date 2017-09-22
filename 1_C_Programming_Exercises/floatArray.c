#include <stdio.h>
#include <math.h>

void PrintArray(float* a, int n);
float Norm(float* a, int n);
float InnerProduct(float* a, int na, float* b, int nb);

int main(int argc, char* argv[])
{
    float A[4] = {114, 514, 1919, 810};
    float B[4] = {38, 324, 14, 122};
    printf("Array A: ");
    PrintArray(A, 4);
    printf("Array B: ");
    PrintArray(B, 4);
    printf("Norm of A: %f\n", Norm(A, 4));
    printf("Inner Product of A and B: %f\n", InnerProduct(A, 4, B, 4));
    return 0;
}

void PrintArray(float* a, int n)
{
    if (n == 0)
    {
        printf("[]\n");
        return;
    }
    else if (n == 1)
    {
        printf("[%f]\n", a[0]);
        return;
    }
    else
    {
        printf("[");
        for (int i = 0; i < n - 1; i++)
        {
            printf("%f, ", a[i]);
        }
        printf("%f]\n", a[n-1]);
        return;
    }
}

float Norm(float* a, int n)
{
    float squareSum = 0;
    for (int i = 0; i < n; i++)
    {
        squareSum += a[i] * a[i];
    }
    return sqrt(squareSum);
}

float InnerProduct(float* a, int na, float* b, int nb)
{
    if (na != nb)
    {
        return 1145141919810;
    }
    else
    {
        float sum = 0;
        for (int i = 0; i < na; i++)
        {
            sum += a[i] * b[i];
        }
        return sum;
    }
}