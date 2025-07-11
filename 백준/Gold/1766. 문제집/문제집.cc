#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> edges(n + 1);
    std::vector<int> indegree(n + 1);
    std::vector<bool> visited(n + 1);

    int start, end;
    while (m--)
    {
        std::cin >> start >> end;
        edges[start].push_back(end);
        ++indegree[end];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0 && !visited[i])
        {
            std::cout << i << " ";
            visited[i] = true;
            for (const int& nextNode : edges[i])
            {
                --indegree[nextNode];
            }
            i = 0;
        }
    }
}