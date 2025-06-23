#include <iostream>
#include <vector>

int n, m;

std::vector<int> vec;

void dfs(int depth)
{
    if (depth > m)
    {
        for (int i = 1; i <= m; ++i)
        {
            std::cout << vec[i] << ' ';
        }
        std::cout << "\n";
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        vec[depth] = i;
        dfs(depth + 1);
    }

}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n >> m;

    vec.resize(n + 1);
    dfs(1);

}