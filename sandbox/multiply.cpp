#include <iostream>
#include <chrono>

int multiply_loop(int, int);
int multiply_recurse(int, int);

int main()
{
    int m, n;

    std::cout << "Enter two integers: ";
    std::cin >> m >> n;

    std::cout << "The product of " << m << " and " << n << "\n";

    auto t1_loop = std::chrono::high_resolution_clock::now();
    std::cout << " is " << multiply_loop(m, n) << " (loop) ";
    auto t2_loop = std::chrono::high_resolution_clock::now();

    auto duration_loop = std::chrono::duration_cast<std::chrono::microseconds>(t2_loop - t1_loop).count();
    std::cout << duration_loop << " microseconds\n";

    auto t1_recurse = std::chrono::high_resolution_clock::now();
    std::cout << " is " << multiply_recurse(m, n) << " (recursion) ";
    auto t2_recurse = std::chrono::high_resolution_clock::now();

    auto duration_recurse = std::chrono::duration_cast<std::chrono::microseconds>(t2_recurse - t1_recurse).count();
    std::cout << duration_recurse << " microseconds\n";

    return 0;
}

int multiply_loop(int m, int n)
{
    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += m;
    }

    return sum;
}

int multiply_recurse(int m, int n)
{
    if (n > 0)
        return m + multiply_recurse(m, n - 1);
    else
        return 0;
}
