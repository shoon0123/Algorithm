#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> dp(n + 1, std::make_pair(0, 1000000));

    dp[1].first = 0;
    dp[1].second = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i * 3 <= n)
        {
            if (dp[i * 3].second > dp[i].second + 1)
            {
                dp[i * 3].first = i;
                dp[i * 3].second = dp[i].second + 1;
            }
        }
        if (i * 2 <= n)
        {
            if (dp[i * 2].second > dp[i].second + 1)
            {
                dp[i * 2].first = i;
                dp[i * 2].second = dp[i].second + 1;
            }
        }
        if (i + 1 <= n)
        {
            if (dp[i + 1].second > dp[i].second + 1)
            {
                dp[i + 1].first = i;
                dp[i + 1].second = dp[i].second + 1;
            }
        }
    }

    std::cout << dp[n].second << "\n";
    while (n >= 1)
    {
        std::cout << n << " ";
        n = dp[n].first;
    }


}