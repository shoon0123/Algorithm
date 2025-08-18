#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> map(n, std::vector<int>(m));
    std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));

    int startX = -1, startY = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
            if (map[i][j] == 2)
            {
                startX = i;
                startY = j;
            }
            if (map[i][j] == 0)
            {
                dist[i][j] = 0; 
            }
        }
    }

    std::queue<std::pair<int, int>> q;
    q.push({startX, startY});
    dist[startX][startY] = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (map[nx][ny] == 0)
                continue;
            if (dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << dist[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}