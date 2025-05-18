#include <iostream>
#include <vector>

std::vector<std::vector<int>> edges;
std::vector<bool> visited;
int answer = 0;

void DFS(int node)
{
	if (visited[node])
	{
		return;
	}
	visited[node] = true;
	++answer;
	for (const int& i : edges[node])
	{
		DFS(i);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	edges.resize(N + 1, std::vector<int>());
	visited.resize(N + 1, false);
	int s, e;
	while (M--)
	{
		std::cin >> s >> e;
		edges[s].push_back(e);
		edges[e].push_back(s);
	}


	DFS(1);
	visited = std::vector<bool>(N + 1, false);
	std::cout << answer-1;
}