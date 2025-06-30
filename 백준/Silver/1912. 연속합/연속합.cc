#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> dp(n + 1, -1001);

    int num;
    int max = -1001;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> num;
        dp[i] = dp[i - 1] > 0 ? dp[i - 1] + num : num;
        max = std::max(max, dp[i]);
    }
    std::cout << max;


}