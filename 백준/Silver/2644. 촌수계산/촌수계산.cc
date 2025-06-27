#include <iostream>
#include <vector>

std::vector<std::vector<int>> tree;
std::vector<bool> visited;

int dfs(int curNode, int findingNode, int depth)
{
    if (curNode == findingNode)
    {
        return depth;
    }

    for (const int& nextNode : tree[curNode])
    {
        if(!visited[nextNode])
        {
            visited[nextNode] = true;
            const int& tmp = dfs(nextNode, findingNode, depth + 1);
            if (tmp != -1)
            {
                return tmp;
            }
        }
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, a, b, m;
    std::cin >> n >> a >> b >> m;
    tree.resize(n + 1);
    visited.resize(n + 1);
    int x, y;
    while (m--)
    {
        std::cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    visited[a] = true;
    std::cout << dfs(a, b, 0);

}