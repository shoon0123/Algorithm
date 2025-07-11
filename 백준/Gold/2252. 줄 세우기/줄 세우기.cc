#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    static int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> edges(N+1);
    std::vector<int> indegree(N + 1);

    for (int i = 0; i < M; ++i) {
        int start, end;
        std::cin >> start >> end;
        edges[start].push_back(end);
        indegree[end]++;
    }
    std::queue<int> queue;

    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            queue.push(i);
        }
    }
    while (!queue.empty()) {
        int now = queue.front();
        queue.pop();
        std::cout << now << " ";
        for (int next : edges[now]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                queue.push(next);
            }
        }
    }
}