#include <iostream>
#include <vector>
#include <set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::set<int> invite;

    for (int friend1 : graph[1])
    {
        invite.insert(friend1);
        for (int friend2 : graph[friend1])
        {
            if (friend2 != 1)
            {
                invite.insert(friend2);
            }
        }
    }

    std::cout << invite.size() << "\n";

    return 0;
}