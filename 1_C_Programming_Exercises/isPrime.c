#include <stdio.h>
#include <math.h>

int isPrime(int x)
{
    int tmp = sqrt(x);
    if (x % 2 == 0)
    {
        return 0;
    }
    for (int i = 3; i <= tmp; i = i + 2)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char* argv[])
{
    printf("5039 is a prime number: %d\n", isPrime(5039));
    return 0;
}