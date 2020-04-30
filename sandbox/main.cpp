#include <iostream>
using namespace std;

int FUN(int x, int y)

{

if (y == 0)

{

return 1;

}

x = x + FUN(x, y-1);

x = x * y;

return x;

}

int main ()
{
    cout << FUN(4,3) << endl;
    return 0;
}
