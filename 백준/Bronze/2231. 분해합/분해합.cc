#include <iostream>
#include <vector>

int bhh(int n)
{
    int sum = n;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    for (int i = 1; i < n; ++i)
    {
        if (bhh(i) == n)
        {
            std::cout << i;
            return 0;
        }
    }
    std::cout << 0;
    return 0;

}