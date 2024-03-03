#include <iostream>
#include <vector>

static int N;
static std::vector<std::vector<int>> tree;
static std::vector<bool> visited;
static std::vector<int> parentNode;

void DFS(int node) 
{
	visited[node] = true;
	for (const int& nextNode : tree[node])
	{
		if (!visited[nextNode])
		{
			parentNode[nextNode] = node;
			DFS(nextNode);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	tree.resize(N + 1);
	visited.resize(N + 1, false);
	parentNode.resize(N + 1);

	for (int i = 1; i < N; ++i) 
	{
		int s, e;
		std::cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}
	DFS(1);
	for (int i = 2; i <= N; ++i) 
	{
		std::cout << parentNode[i] << '\n';
	}
}