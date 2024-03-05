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
    std::vector<std::vector<int>> edges(N + 1);
    std::vector<int> indegree(N + 1, 0);

    while (M--) {
        int start, end;
        std::cin >> start >> end;
        edges[start].push_back(end);
        ++indegree[end];
    }

    std::queue<int> queue;
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            queue.push(i);
        }
    }
    while (!queue.empty()) {
        int& now = queue.front();
        std::cout << now << " ";
        for (const int& next : edges[now]) {
            if (--indegree[next] == 0) {
                queue.push(next);
            }
        }
        queue.pop();
    }
}