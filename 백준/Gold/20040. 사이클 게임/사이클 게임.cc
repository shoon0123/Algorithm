#include <iostream>
#include <vector>

static std::vector<int> parent;

int find(int a)
{
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

void unionfunc(int a, int b)
{
    parent[find(a)] = find(b);
}

bool isSameUnion(int a, int b)
{
    return find(a) == find(b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    parent.resize(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    int dot1, dot2;
    int endRound = 0;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> dot1 >> dot2;
        if (endRound == 0)
        {
            if (isSameUnion(dot1, dot2))
            {
                endRound = i;
                break;
            }
            else
            {
                unionfunc(dot1, dot2);
            }
        }
    }
    std::cout << endRound;
}