extern float test1(float x);

float Trap(float a, float b, int n, float h)
{
    float integral;
    float x;
    
    integral = (test1(a) + test1(b)) / 2.0;
    x = a;
    for (int i = 1; i <= n-1; i++)
    {
        x = x + h;
        integral += test1(x);
    }
    return integral * h;
}