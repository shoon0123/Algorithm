#include <iostream>
#include <vector>
#include <string>

int lcsLength(std::string s1, std::string s2)
{
    const int length1 = s1.size();
    const int length2 = s2.size();
    std::vector<std::vector<int>> dp(length1 + 1, std::vector<int>(length2 + 1, 0));

    for (int i = 1; i <= length1; ++i)
    {
        for (int j = 1; j <= length2; ++j)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[length1][length2];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string s1, s2;

    std::cin >> s1 >> s2;
    std::cout << lcsLength(s1, s2);
}