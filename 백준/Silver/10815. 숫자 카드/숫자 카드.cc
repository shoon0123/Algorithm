#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> cards(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> cards[i];
    }

    std::sort(cards.begin(), cards.end());

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i)
    {
        int target;
        std::cin >> target;

        if (std::binary_search(cards.begin(), cards.end(), target))
        {
            std::cout << "1 ";
        }
        else
        {
            std::cout << "0 ";
        }
    }

    return 0;
}