#include <iostream>
#include <vector>
#include <queue>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> edges(n + 1);
    std::vector<int> indegree(n + 1);

    int start, end;
    while (m--)
    {
        std::cin >> start >> end;
        edges[start].push_back(end);
        ++indegree[end];
    }

    std::priority_queue<int,std::vector<int>,std::greater<int>> q;
    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int top;
    while (!q.empty())
    {
        top = q.top();
        q.pop();
        std::cout << top << " ";
        for (const int& nextNode : edges[top])
        {
            if (--indegree[nextNode] == 0)
            {
                q.push(nextNode);
            }
        }
    }
}