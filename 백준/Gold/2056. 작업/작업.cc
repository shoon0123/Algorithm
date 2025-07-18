#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;

    std::cin >> n;

    std::vector<int> time(n + 1);
    std::vector<int> indegree(n + 1);
    std::vector<std::vector<int>> graph(n + 1);
    std::vector<int> dp(n + 1);

    int count;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> time[i] >> count;
        while (count--)
        {
            int pre;
            std::cin >> pre;
            graph[pre].push_back(i);
            indegree[i]++;
        }
    }

    std::queue<int> queue;

    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0)
        {
            queue.push(i);
            dp[i] = time[i];
        }
    }
    while (!queue.empty())
    {
        const int cur = queue.front();
        queue.pop();
        for (const int& next : graph[cur])
        {
            --indegree[next];
            dp[next] = std::max(dp[next], dp[cur] + time[next]);
            if (indegree[next] == 0)
            {
                queue.push(next);
            }
        }
    }
    int result = -1;
    for (const int& time : dp)
    {
        result = std::max(result, time);
    }

    std::cout << result << "\n";
}
