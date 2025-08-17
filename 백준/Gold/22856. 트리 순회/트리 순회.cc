#include <iostream>
#include <vector>

struct Node
{
    int left, right;
};

std::vector<Node> tree;
int N;

int getRightmostDepth(int node)
{
    int depth = 0;
    while (tree[node].right != -1)
    {
        node = tree[node].right;
        depth++;
    }
    return depth;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    tree.resize(N + 1);

    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        tree[a].left = b;
        tree[a].right = c;
    }

    int totalMoves = (N - 1) * 2;

    int depth = getRightmostDepth(1);

    std::cout << totalMoves - depth << "\n";

    return 0;
}
