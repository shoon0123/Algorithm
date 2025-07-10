#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> wine(n + 1);
    std::vector<int> dp(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> wine[i];
    }
    if (n == 1)
    {
        std::cout << wine[1];
        return 0;
    }
    if (n == 2)
    {
        std::cout << wine[1] + wine[2];
        return 0;
    }

    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = std::max({ dp[i - 1],
                        dp[i - 2] + wine[i],
                        dp[i - 3] + wine[i - 1] + wine[i] });
    }
    std::cout << dp[n];
}