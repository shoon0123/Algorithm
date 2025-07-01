#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> vec(n + 1);


    for (int i = 1; i <= n; ++i)
    {
        std::cin >> vec[i];
    }

    if (n == 1)
    {
        std::cout << vec[1];
        return 0;
    }

    std::vector<int> dp(n + 1);

    dp[1] = vec[1];
    dp[2] = vec[1] + vec[2];

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = std::max(dp[i - 2] + vec[i], dp[i - 3] + vec[i - 1] + vec[i]);
    }
    std::cout << dp[n];

}