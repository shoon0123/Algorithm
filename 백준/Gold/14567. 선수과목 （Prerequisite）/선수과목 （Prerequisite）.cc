#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> graph(N + 1,std::vector<int>());
    std::vector<int> indegree(N + 1);
    std::vector<int> semester(N + 1, 1);
    std::queue<int> queue;

    int start, end;
    while (M--)
    {
        std::cin >> start >> end;
        graph[start].push_back(end);
        ++indegree[end];
    }
    for (int i = 1; i <= N; ++i)
    {
        if (indegree[i] == 0)
        {
            queue.push(i);
        }
    }
    while(!queue.empty())
    {
        const int now = queue.front();
        queue.pop();

        for (const int& next : graph[now]) 
        {
            --indegree[next];
            semester[next] = std::max(semester[next], semester[now] + 1);
            if (indegree[next] == 0)
            {
                queue.push(next);
            }
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        std::cout << semester[i] << ' ';
    }
}