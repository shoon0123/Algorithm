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
    std::vector<int> dpIncrease(n + 1, 1);
    std::vector<int> dpDecrease(n + 1, 1);

    for (int i = 1; i <= n; ++i)
    {
        std::cin >> vec[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (vec[i] > vec[j])
            {
                dpIncrease[i] = std::max(dpIncrease[i], dpIncrease[j] + 1);
            }
        }
    }
    for (int i = n; i > 0; --i)
    {
        for (int j = n; j > i; --j)
        {
            if (vec[i] > vec[j])
            {
                dpDecrease[i] = std::max(dpDecrease[i], dpDecrease[j] + 1);
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= n; ++i)
    {
        max = std::max(max, dpIncrease[i] + dpDecrease[i] - 1);
    }
    std::cout << max;
}