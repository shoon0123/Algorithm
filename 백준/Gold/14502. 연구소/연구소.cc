#include <iostream>
#include <vector>
#include <queue>

int N, M;
int lab[8][8];                // 연구소 지도
int temp[8][8];               // 벽 세운 뒤 지도 (복사본)
int dx[4] = {1, -1, 0, 0};    // 상하좌우 이동
int dy[4] = {0, 0, 1, -1};
int result = 0;

void spreadVirus()
{
    int virusMap[8][8];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            virusMap[i][j] = temp[i][j];
        }
    }

    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (virusMap[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (virusMap[nx][ny] == 0)
                {
                    virusMap[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }

    int safe = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (virusMap[i][j] == 0)
            {
                safe++;
            }
        }
    }

    result = std::max(result, safe);
}

void buildWall(int count)
{
    if (count == 3)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                temp[i][j] = lab[i][j];
            }
        }

        spreadVirus();
        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (lab[i][j] == 0)
            {
                lab[i][j] = 1;
                buildWall(count + 1);
                lab[i][j] = 0;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> lab[i][j];
        }
    }

    buildWall(0);
    std::cout << result << "\n";
    return 0;
}