#include <iostream>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long n;
    std::cin >> n;
    long result = n;

    for (long p = 2; p <= sqrt(n); ++p) {
        if (n % p == 0) {
            result = result - result / p;
            while (n % p == 0) {
                n /= p;
            }
        }
    }
    if (n > 1) {
        result = result - result / n;
    }
    std::cout << result;

}