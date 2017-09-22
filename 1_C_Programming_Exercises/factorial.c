#include <stdio.h>

int Factorial(int x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return x * Factorial(x-1);
    }
}

int main(int argc, char* argv[])
{
    printf("Factorial of 5: %d\n", Factorial(5));
    return 0;
}