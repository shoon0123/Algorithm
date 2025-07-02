#include <iostream>
#include <vector>

struct rgb
{
    int red = 0;
    int green = 0;
    int blue = 0;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<rgb> vec(n + 1);
    std::vector<rgb> dp(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> vec[i].red;
        std::cin >> vec[i].green;
        std::cin >> vec[i].blue;
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i].red = std::min(dp[i - 1].blue + vec[i].red, dp[i - 1].green + vec[i].red);
        dp[i].blue = std::min(dp[i - 1].red + vec[i].blue, dp[i - 1].green + vec[i].blue);
        dp[i].green = std::min(dp[i - 1].blue + vec[i].green, dp[i - 1].red + vec[i].green);
    }

    std::cout << std::min(dp[n].red, std::min(dp[n].green, dp[n].blue));


}