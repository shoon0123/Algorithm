#include <iostream>
#include <vector>

const int MOD = 1000000000;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<long long>> dp(K + 1, std::vector<long long>(N + 1, 0));

    for (int n = 0; n <= N; n++)
    {
        dp[1][n] = 1;
    }

    for (int k = 2; k <= K; k++)
    {
        for (int n = 0; n <= N; n++)
        {
            for (int i = 0; i <= n; i++)
            {
                dp[k][n] = (dp[k][n] + dp[k - 1][n - i]) % MOD;
            }
        }
    }

    std::cout << dp[K][N] << "\n";
    return 0;
}