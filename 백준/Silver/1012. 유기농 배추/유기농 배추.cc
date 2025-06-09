#include <iostream>
#include <vector>

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int M, N;

void dfs(int x, int y, std::vector<std::vector<bool>>&field)
{
	field[y][x] = false;
	int nextX, nextY;
	for (int i = 0; i < 4; ++i)
	{
		nextX = x + dx[i];
		nextY = y + dy[i];
		if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)
		{
			continue;
		}
		if (field[nextY][nextX])
		{
			dfs(nextX, nextY, field);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T, K;
	int X, Y, count;

	std::cin >> T;
	while (T--)
	{
		std::cin >> M >> N >> K;
		std::vector<std::vector<bool>> field(N, std::vector<bool>(M, false));
		count = 0;
		while (K--)
		{
			std::cin >> X >> Y;
			field[Y][X] = true;
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (field[i][j])
				{
					++count;
					dfs(j, i, field);
				}
			}
		}
		std::cout << count << '\n';
	}

}