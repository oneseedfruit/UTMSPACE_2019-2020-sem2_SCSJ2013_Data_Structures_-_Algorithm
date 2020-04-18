#include <iostream>
using namespace std;

int fun1(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n <= 1)
    {
        return 1;
    }
    else
    {
        return fun1(n -1) + fun1(n - 2);
    }
}

int main()
{
    for (int i = 0; i <= 5; ++i)
        cout << fun1(i) << endl;

    return 0;
}
