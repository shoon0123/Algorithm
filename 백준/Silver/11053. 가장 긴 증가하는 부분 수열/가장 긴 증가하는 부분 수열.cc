#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> A(n + 1);
    std::vector<int> dp(n + 1, 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> A[i];
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (A[i] > A[j])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        max = std::max(dp[i], max);
    }

    std::cout << max;
}