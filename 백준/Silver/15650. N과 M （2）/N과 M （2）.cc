#include <iostream>
#include <vector>

int N, M;
std::vector<int> vec;
std::vector<bool> visited;

void dfs(int num, int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; ++i)
        {
            std::cout << vec[i] << ' ';
        }
        std::cout << '\n';
        return;
    }
    for (int i = num; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            vec[cnt] = i;
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	std::cin >> N >> M;

    vec.resize(M);
    visited.resize(N+1,false);

    dfs(1, 0);
}