#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> boxes(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> boxes[i];
    }

    std::vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (boxes[j] < boxes[i])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int answer = *std::max_element(dp.begin(), dp.end());
    std::cout << answer << "\n";

    return 0;
}
