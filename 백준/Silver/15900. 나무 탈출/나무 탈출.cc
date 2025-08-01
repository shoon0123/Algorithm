#include <iostream>
#include <vector>

std::vector<std::vector<int>> tree;
std::vector<bool> visited;
int totalDepthSum = 0;

void dfs(int node, int depth)
{
    visited[node] = true;
    bool isLeaf = true;

    for (int next : tree[node])
    {
        if (!visited[next])
        {
            isLeaf = false;
            dfs(next, depth + 1);
        }
    }

    if (isLeaf)
    {
        totalDepthSum += depth;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    tree.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    if (totalDepthSum % 2 == 1)
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }

    return 0;
}