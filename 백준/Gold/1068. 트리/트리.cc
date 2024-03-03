#include <iostream>
#include <vector>
#include <algorithm>

static int N, root, count = 0;
static std::vector<int> parentNode;
static std::vector<std::vector<int>> tree;

void DFS(int node)
{
	if (tree[node].empty())
	{
		++count;
		return;
	}
	for (const int& nextNode : tree[node]) 
	{
		DFS(nextNode);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	parentNode.resize(N);
	tree.resize(N);
	for (int i = 0; i < N; ++i) 
	{
		std::cin >> parentNode[i];
		if (parentNode[i] == -1) 
		{
			root = i;
		}
		else
		{
			tree[parentNode[i]].push_back(i);
		}
	}
	int deleteNode;
	std::cin >> deleteNode;

	if (deleteNode == root)
	{
		std::cout << count;
		return 0;
	}

	std::vector<int>& v = tree[parentNode[deleteNode]];
	v.erase(remove(v.begin(), v.end(), deleteNode), v.end());
	DFS(root);
	std::cout << count;
}