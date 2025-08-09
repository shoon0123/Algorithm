#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct Edge
{
    int to;
    int weight;
};

const long long INF = INT_MAX; 

std::vector<long long> Dijkstra(int start, const std::vector<std::vector<Edge>>& graph)
{
    std::vector<long long> dist(graph.size(), INF);
    dist[start] = 0;

    using Node = std::pair<long long, int>;
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        long long currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > dist[currentNode])
        {
            continue;
        }

        for (const auto& edge : graph[currentNode])
        {
            long long nextDist = currentDist + edge.weight;
            if (nextDist < dist[edge.to])
            {
                dist[edge.to] = nextDist;
                pq.push({ nextDist, edge.to });
            }
        }
    }

    return dist;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, e;
    std::cin >> n >> e;

    std::vector<std::vector<Edge>> graph(n + 1);

    for (int i = 0; i < e; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    int v1, v2;
    std::cin >> v1 >> v2;

    auto distFrom1 = Dijkstra(1, graph);
    auto distFromV1 = Dijkstra(v1, graph);
    auto distFromV2 = Dijkstra(v2, graph);

    long long path1 = distFrom1[v1] + distFromV1[v2] + distFromV2[n];
    long long path2 = distFrom1[v2] + distFromV2[v1] + distFromV1[n];

    long long answer = std::min(path1, path2);

    if (answer >= INF)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << answer;
    }

    return 0;
}