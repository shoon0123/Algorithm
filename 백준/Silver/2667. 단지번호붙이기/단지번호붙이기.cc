#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int n;
std::vector<std::vector<int>> map;
std::vector<std::vector<bool>> visited;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(int x, int y)
{
    visited[x][y] = true;
    int count = 1;

    for(int i = 0; i < 4; ++i)
    {
        const int nextX = x + dx[i];
        const int nextY = y + dy[i];

        if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
        {
            continue;
        }
        else if (!visited[nextX][nextY] &&  map[nextX][nextY] == 1)
        {
            count += dfs(nextX, nextY);
        }
    }
    return count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;
    map.resize(n, std::vector<int>(n));
    visited.resize(n, std::vector<bool>(n, false));
    
    std::string s;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> s;
        for (int j = 0; j < n; ++j)
        {
            if (s[j] == '1')
            {
                map[i][j] = 1;
            }
        }
    }

    std::vector<int> vec;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                vec.push_back(dfs(i, j));
            }
        }
    }
    std::sort(vec.begin(), vec.end());

    std::cout << vec.size() << "\n";
    for (const int& i : vec)
    {
        std::cout << i << "\n";
    }

}
