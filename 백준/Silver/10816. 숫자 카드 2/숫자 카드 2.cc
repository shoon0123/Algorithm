#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<int> cards(N);

    for (int i = 0; i < N; ++i)
        std::cin >> cards[i];

    std::sort(cards.begin(), cards.end());

    int M;
    std::cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int query;
        std::cin >> query;
        auto lower = std::lower_bound(cards.begin(), cards.end(), query);
        auto upper = std::upper_bound(cards.begin(), cards.end(), query);
        std::cout << upper - lower << " ";
    }
    std::cout << '\n';

    return 0;
}