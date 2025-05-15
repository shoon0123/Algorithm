#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::vector<int> vec(N);

    int answer = 0;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> vec[i];
    }
    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < N-2; ++i)
    {
        for (int j = i+1; j < N - 1; ++j)
        {
            for (int k = j + 1; k < N ; ++k)
            {
                const int sum = vec[i] + vec[j] + vec[k];
                if (sum > answer && sum <= M)
                {
                    answer = sum;
                }
            }
        }
    }
 


    std::cout << answer;

}