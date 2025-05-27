#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long A, B;

    std::cin >> A >> B;
    int result = 1;

    while (true)
    {
        if (A == B)
        {
            break;
        }
        else if (A > B)
        {
            result = -1;
            break;
        }
        else if (B % 10 == 1)
        {
            B /= 10;
        }
        else if (B % 2 == 0)
        {
            B /= 2;
        }
        else
        {
            result = -1;
            break;
        }
        ++result;
    }

    std::cout << result;
}