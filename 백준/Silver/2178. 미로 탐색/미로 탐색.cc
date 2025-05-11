#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

int N, M;
static std::vector<std::vector<int>> maze;
static std::vector<std::vector<bool>> visited;
static std::queue<std::tuple<int,int,int>> queue;
void BFS(int x, int y);
void pushQueue(int x, int y, int count);
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	
	std::cin >> N >> M;
	maze.resize(N);
	visited.resize(N);
	
	for (int i = 0; i < N; ++i) {
		std::string str;
		std::cin >> str;
		maze[i].resize(M);
		visited[i].resize(M,false);
		for (int j = 0; j < M; ++j){
			maze[i][j] = str[j] - '0';
		}
	}

	BFS(0, 0);
	
}

void BFS(int x, int y) {
	pushQueue(x, y, 2);
	if (x == N-1 && y == M-1) {
		std::cout << 1;
	}
	while (!queue.empty()) {
		std::tuple<int, int, int> front = queue.front();
		if (std::get<0>(front) == N-1 && std::get<1>(front) == M-1) {
			std::cout << std::get<2>(front);
			break;
		}
		queue.pop();
		pushQueue(std::get<0>(front), std::get<1>(front), std::get<2>(front)+1);
	}
}

void pushQueue(int x, int y, int count){
	if (x > 0 && maze[x - 1][y] != 0 && !visited[x - 1][y]) {
		visited[x - 1][y] = true;
		queue.push(std::make_tuple(x - 1, y, count));
	}
	if (y > 0 && maze[x][y - 1] != 0 && !visited[x][y - 1]) {
		visited[x][y-1] = true;
		queue.push(std::make_tuple(x, y - 1, count));
	}
	if (x < N - 1 && maze[x + 1][y] != 0 && !visited[x + 1][y]) {
		visited[x + 1][y] = true;
		queue.push(std::make_tuple(x + 1, y, count));
	}
	if (y < M - 1 && maze[x][y + 1] != 0 && !visited[x][y + 1]) {
		visited[x][y+1] = true;
		queue.push(std::make_tuple(x, y + 1, count));
	}
}