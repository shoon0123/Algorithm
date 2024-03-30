#include <iostream>
#include <vector>
#include <queue>

static int N, M;
static std::vector<std::vector<int>> tree;
static std::vector<int> depth;
static std::vector<int> parent;
static std::vector<bool> visited;

int LCA(int a, int b);
void BFS(int node);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	tree.resize(N + 1);
	depth.resize(N + 1);
	parent.resize(N + 1);
	visited.resize(N + 1);

	while(--N)
	{
		int s, e;
		std::cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}
	BFS(1);
	std::cin >> M;
	while(M--)
	{
		int a, b;
		std::cin >> a >> b;
		std::cout << LCA(a, b) << '\n';
	}
}

int LCA(int a, int b)
{
	if (depth[a] < depth[b])
	{
		int temp = a;
		a = b;
		b = temp;
	}
	while (depth[a] != depth[b])
	{
		a = parent[a];
	}
	while (a != b)
	{
		a = parent[a];
		b = parent[b];
	}
	return a;
}

void BFS(int node)
{
	std::queue<int> queue;
	queue.push(node);
	visited[node] = true;

	while (!queue.empty())
	{
		const int now_node = queue.front();
		queue.pop();
		for (const int& next : tree[now_node])
		{
			if (!visited[next])
			{
				visited[next] = true;
				queue.push(next);
				parent[next] = now_node;
				depth[next] = depth[now_node] + 1;
			}
		}
	}
}