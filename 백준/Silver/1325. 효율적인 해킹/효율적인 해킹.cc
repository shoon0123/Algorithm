#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


int N, M;
std::vector<std::vector<int>> edges;
std::vector<int> visited;
std::vector<int> depth;

void BFS(int node) {
    std::queue<int> queue;
    int count = 0;
    queue.push(node);
    visited[node] = 0;
    while (!queue.empty()) {
        int front = queue.front();
        queue.pop();
        for (int i : edges[front]) {
            if (visited[i] == -1) {
                visited[i] = 0;
                queue.push(i);
                count++;
            }
        }
    }
    
    
    depth[node] = count;
    fill(visited.begin(), visited.end(), -1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;
    edges.resize(N + 1);
    visited.resize(N + 1, -1);
    depth.resize(N + 1, -1);
    for (int i = 0; i < M; ++i) {
        int start, end;
        std::cin >> start >> end;
        edges[end].push_back(start);
    }
    for (int i = 1; i <= N; ++i){
        BFS(i);
    }
    int max = -2;
    std::vector<int> computers;
    for (int i = 1; i <= N; ++i) {
        if (max < depth[i]) {
            max = depth[i];
            computers.clear();
            computers.push_back(i);
        }
        else if (max == depth[i]) {
            computers.push_back(i);
        }
    }
    std::sort(computers.begin(), computers.end());
    for (int i : computers) {
        std::cout << i << ' ';
    }
}