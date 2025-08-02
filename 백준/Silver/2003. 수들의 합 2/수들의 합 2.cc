#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> vec(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        int num;
        std::cin >> num;
        vec[i] = vec[i - 1] + num;
    }
    int s = 0;
    int e = 0;
    int count = 0;
    while (e <= N)
    {
        if (vec[e] - vec[s] == M)
        {
            ++count;
            ++e;
        }
        else if (vec[e] - vec[s] > M)
        {
            ++s;
        }
        else
        {
            ++e;
        }
    }
    std::cout << count;


    return 0;
}