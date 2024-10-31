#include <iostream>



int sorozat(int n, int kezdo, int diff)
{
    if (n == 1)
    {
        return kezdo;
    }
    sorozat(n - 1, kezdo + diff, diff);
}

int main()
{
    std::cout << sorozat(10, 5, 2) << std::endl;
    return 0;
}
