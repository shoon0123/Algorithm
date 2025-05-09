#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    const int MAX = 100000;

    int N, M;
    std::cin >> N >> M;
    std::vector<int> vec(N),check(MAX+1);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> vec[i];
    }

    int left = 0;
    int right = 0;
    int maxValue = 0;

    while (true)
    {
        if (right >= N)
        {
            maxValue = std::max(maxValue, right-left);
            break;
        }

        if (check[vec[right]] < M)
        {
            ++check[vec[right]];
            ++right;
        }
        else
        {
            --check[vec[left]];
            maxValue = std::max(maxValue, right - left);
            ++left;
        }
    }
    std::cout << maxValue;
    

}