#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> degree(N + 1, 0);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    int Q;
    std::cin >> Q;

    while (Q--)
    {
        int t, k;
        std::cin >> t >> k;
        if (t == 1)
        {
            if (degree[k] == 1)
            {
                std::cout << "no\n";
            }
            else
            {
                std::cout << "yes\n";
            }
        }
        else
        {
            std::cout << "yes\n";
        }
    }

    return 0;
}