#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    if (N % 2 == 1)
    {
        std::cout << "SK\n";
    }
    else
    {
        std::cout << "CY\n";
    }

    return 0;
}