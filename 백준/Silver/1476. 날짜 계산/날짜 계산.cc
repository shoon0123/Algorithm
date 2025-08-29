#include <iostream>

int main()
{
    int E, S, M;
    std::cin >> E >> S >> M;

    int year = 1;
    while (true)
    {
        int e = (year % 15 == 0) ? 15 : year % 15;
        int s = (year % 28 == 0) ? 28 : year % 28;
        int m = (year % 19 == 0) ? 19 : year % 19;

        if (e == E && s == S && m == M)
        {
            std::cout << year;
            break;
        }
        year++;
    }
    return 0;
}
