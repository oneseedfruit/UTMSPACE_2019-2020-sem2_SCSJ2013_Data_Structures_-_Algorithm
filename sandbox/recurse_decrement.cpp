#include <iostream>

void decrement(int);

int main()
{
    decrement(5);    
    return 0;
}

void decrement(int n)
{
    if (n > 0)
    {
        std::cout << n << "\n"; 
        decrement(n - 1);
    }
}