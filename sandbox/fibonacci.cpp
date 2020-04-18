#include <iostream>

int fibonacci(int);

int main()
{
    int n = 32;

    for (int i = 0; i < n; ++i)
    {
        std::cout << fibonacci(i) << " ";
    }

    return 0;
}

int fibonacci(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
