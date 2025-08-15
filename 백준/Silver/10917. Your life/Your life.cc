#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> dist(N + 1, -1);
    std::queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int nxt : adj[curr])
        {
            if (dist[nxt] == -1)
            {
                dist[nxt] = dist[curr] + 1;
                q.push(nxt);
            }
        }
    }

    std::cout << dist[N] << "\n";
    return 0;
}