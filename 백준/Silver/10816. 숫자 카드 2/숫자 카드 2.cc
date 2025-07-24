#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N;

    std::unordered_map<int, int> countMap;

    for (int i = 0; i < N; ++i)
    {
        int num;
        std::cin >> num;
        ++countMap[num];
    }

    std::cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int query;
        std::cin >> query;
        std::cout << countMap[query] << " ";
    }

    std::cout << '\n';
    return 0;
}