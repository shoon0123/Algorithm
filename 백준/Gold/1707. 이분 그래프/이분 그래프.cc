#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int K;
    std::cin >> K;
    
    while (K--) {
        int V, E;
        std::cin >> V >> E;
        std::vector<std::vector<int>> edges(V + 1);
        std::vector<int> visited(V + 1, -1);
        std::queue<int> queue;
        while (E--) {
            int start, end;
            std::cin >> start >> end;
            edges[start].push_back(end);
            edges[end].push_back(start);
        }
        bool isBipartiteGraph = true;
        for (int i = 1; i <= V; ++i) {
            if (visited[i] == -1) {
                queue.push(i);
                visited[i] = 0;
                while (!queue.empty()) {
                    int front = queue.front();
                    queue.pop();
                    for (int nextNode : edges[front]) {
                        if (visited[nextNode] == -1) {
                            queue.push(nextNode);
                            visited[nextNode] = visited[front]+1;
                        }
                        else if(visited[nextNode]%2 == visited[front]%2){
                            isBipartiteGraph = false;
                            break;
                        }
                    }
                    if (!isBipartiteGraph) {
                        break;
                    }
                }
                if (!isBipartiteGraph) {
                    break;
                }
            }
        }
        if (isBipartiteGraph) {
            std::cout << "YES" << '\n';
        }
        else {
            std::cout << "NO" << '\n';
        }
    }
} 