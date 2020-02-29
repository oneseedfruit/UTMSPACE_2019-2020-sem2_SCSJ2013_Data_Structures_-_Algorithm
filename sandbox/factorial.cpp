#include <iostream>
#include <chrono>

unsigned long int factorial_loop(int);
unsigned long int factorial_recurse(int);

int main()
{
    int n;

    std::cout << "The factorial of: ";
    std::cin >> n;

    auto t1_loop = std::chrono::high_resolution_clock::now();
    std::cout << " is " << factorial_loop(n) << " (loop) ";
    auto t2_loop = std::chrono::high_resolution_clock::now();

    auto duration_loop = std::chrono::duration_cast<std::chrono::microseconds>(t2_loop - t1_loop).count();
    std::cout << duration_loop << " microseconds\n";

    auto t1_recurse = std::chrono::high_resolution_clock::now();
    std::cout << " is " << factorial_recurse(n) << " (recursion) ";
    auto t2_recurse = std::chrono::high_resolution_clock::now();

    auto duration_recurse = std::chrono::duration_cast<std::chrono::microseconds>(t2_recurse - t1_recurse).count();
    std::cout << duration_recurse << " microseconds\n";

    return 0;
}

unsigned long int factorial_loop(int n)
{
    unsigned long int factorial = 1;

    for (int i = n; i > 0; --i)
    {
        factorial *= i;
    }

    return factorial;
}

unsigned long int factorial_recurse(int n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial_recurse(n - 1);
}
