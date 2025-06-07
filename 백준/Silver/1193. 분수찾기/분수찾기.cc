#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int X;
    std::cin >> X;
    int sum = 0;

    int i = 1;
    while (true)
    {
        sum += i;
        if (sum >= X)
        {
            if (i % 2 == 1)
            {
                std::cout << sum - X + 1 << '/' << i - sum + X;
                break;
            }
            else
            {
                std::cout << i - sum + X << '/' << sum - X + 1;
                break;
            }
        }
        ++i;
    }
}