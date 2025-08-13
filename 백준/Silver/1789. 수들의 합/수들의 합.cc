#include <iostream>

int main()
{
    long long S;
    std::cin >> S;

    long long sum = 0;
    long long count = 0;

    for (long long i = 1; ; i++)
    {
        if (sum + i > S)
        {
            break;
        }
        sum += i;
        count++;
    }

    std::cout << count << "\n";
    return 0;
}