#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

static std::vector<std::vector<int>> edges;
static std::vector<bool> visited;
static std::queue<int> bfsQueue;
void DFS(int node);
void BFS(int node);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M, V;
	std::cin >> N >> M >> V;
	edges.resize(N+1);
	visited = std::vector<bool>(N+1,false);
	for (int i = 0; i < M; ++i) {
		int start, end;
		std::cin >> start >> end;
		edges[start].push_back(end);
		edges[end].push_back(start);
	}
	 for (std::vector<int>& edge : edges) {
		std::sort(edge.begin(), edge.end());
	}

	DFS(V);
	std::fill(visited.begin(), visited.end(),false);
	std::cout << '\n';
	BFS(V);
}

void DFS(int node) {
	std::cout << node << ' ';
	visited[node] = true;
	for (int i : edges[node]) {
		if (!visited[i]) {
			DFS(i);
		}
	}	
}
void BFS(int node) {
	std::cout << node << ' ';
	visited[node] = true;
	for (int i : edges[node]) {
		bfsQueue.push(i);
	}

	while (!bfsQueue.empty()) {
		int next = bfsQueue.front();
		bfsQueue.pop();
		if (!visited[next]) {
			BFS(next);
		}
	}
}