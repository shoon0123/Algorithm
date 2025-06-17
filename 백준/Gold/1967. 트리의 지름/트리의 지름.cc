#include <iostream>
#include <vector>

std::vector<std::vector<std::pair<int, int>>> tree;
std::vector<bool> visited;

int DFS(int curNode, int weight)
{
	visited[curNode] = true;
	int max = weight;
	for (const std::pair<int, int>& nextNode : tree[curNode])
	{
		if (!visited[nextNode.first])
		{
			const int& w = DFS(nextNode.first, weight + nextNode.second);
			max = std::max(max, w);
		}
	}
	return max;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	std::cin >> n;

	tree.resize(n+1, std::vector<std::pair<int,int>>());
	visited.resize(n+1, false);

	int s, e, w;
	for (int i = 1; i < n; ++i)
	{
		std::cin >> s >> e >> w;

		tree[s].push_back(std::make_pair(e, w));
		tree[e].push_back(std::make_pair(s, w));
	}

	int max = 0;

	for (int i = 1; i <= n; ++i)
	{
		max = std::max(max, DFS(i, 0));
		for (int i = 1; i <= n; ++i)
		{
			visited[i] = false;
		}
	}
	std::cout << max;
}