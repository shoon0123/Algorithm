#include <iostream>
#include <vector>
#include <queue>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> campus(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> campus[i];
    }

    int startX = -1, startY = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (campus[i][j] == 'I')
            {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    q.push({startX, startY});
    visited[startX][startY] = true;

    int count = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (visited[nx][ny] || campus[nx][ny] == 'X')
                continue;

            visited[nx][ny] = true;
            if (campus[nx][ny] == 'P')
                count++;

            q.push({nx, ny});
        }
    }

    if (count == 0)
    {
        std::cout << "TT\n";
    }
    else
    {
        std::cout << count << "\n";
    }

    return 0;
}