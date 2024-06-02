#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

typedef std::pair<int, int> edge;
static int V, E, K;
static std::vector<int> minDistance;
static std::vector<bool> visited;
static std::vector<std::vector<edge>> edgeList;
static std::priority_queue<edge, std::vector<edge>, std::greater<edge>> queue;

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> V >> E;
	std::cin >> K;
	minDistance.resize(V + 1,INT_MAX);
	visited.resize(V + 1, false);
	edgeList.resize(V + 1);

	for (int i = 0; i < E; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		edgeList[u].push_back(std::make_pair(v, w));
	}
	queue.push(std::make_pair(0, K));
	minDistance[K] = 0;
	while (!queue.empty()) {
		edge current = queue.top();
		queue.pop();
		int c_v = current.second;
		if (visited[c_v]) {
			continue;
		}
		visited[c_v] = true;
		for (int i = 0; i < edgeList[c_v].size(); ++i) {
			edge tmp = edgeList[c_v][i];
			int next = tmp.first;
			int value = tmp.second;

			if (minDistance[next] > minDistance[c_v] + value) {
				minDistance[next] = value + minDistance[c_v];
				queue.push(std::make_pair(minDistance[next], next));
			}
		}
	}
	for (int i = 1; i <= V; ++i) {
		if (visited[i]) {
			std::cout << minDistance[i] << '\n';
		}
		else {
			std::cout << "INF" << '\n';
		}
	}
}