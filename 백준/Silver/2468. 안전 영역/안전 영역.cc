#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
std::vector<std::vector<int>> board;
std::vector<std::vector<bool>> visited;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int x, int y, int h)
{
    std::queue<std::pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            {
                continue;
            }
            if (visited[nx][ny])
            {
                continue;
            }
            if (board[nx][ny] <= h)
            {
                continue;
            }
            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N;
    board.assign(N, std::vector<int>(N));
    int maxH = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> board[i][j];
            maxH = std::max(maxH, board[i][j]);
        }
    }

    int result = 1; 
    for (int h = 0; h <= maxH; h++)
    {
        visited.assign(N, std::vector<bool>(N, false));
        int cnt = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j] && board[i][j] > h)
                {
                    bfs(i, j, h);
                    cnt++;
                }
            }
        }
        result = std::max(result, cnt);
    }

    std::cout << result << "\n";
    return 0;
}