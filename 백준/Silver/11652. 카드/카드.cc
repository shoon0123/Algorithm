#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<long> vec(N);


    for (int i = 0; i < N; ++i)
    {
        std::cin >> vec[i];
    }
    std::sort(vec.begin(), vec.end());

    long max = 0;
    long count = 0;
    long answer = vec[0];
    for (int i = 1; i < N; ++i)
    {
        if (vec[i] == vec[i - 1])
        {
            ++count;
            if (count > max)
            {
                max = count;
                answer = vec[i];
            }
        }
        else
        {
            count = 0;
        }
    }
        
    std::cout << answer;

}