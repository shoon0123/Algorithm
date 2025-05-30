#include <iostream>
#include <vector>

#define MAX 9

int N, M;
int arr[MAX];
bool visited[MAX];

void dfs(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
		return;
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			if (!visited[i])
			{
				visited[i] = true;
				arr[depth] = i;
				dfs(depth + 1);
				visited[i] = false;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	
	dfs(0);
}