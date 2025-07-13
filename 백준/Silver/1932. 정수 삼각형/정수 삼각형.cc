#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;
    int num;
    std::vector<int> dp(n + 2, 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j >= 1; --j)
        {
            std::cin >> num;
            dp[j] = std::max(dp[j], dp[j - 1]) + num;
        }
    }
    int max = 0;
    for (int i = 1; i <= n; ++i)
    {
        max = std::max(max, dp[i]);
    }
    std::cout << max;
}