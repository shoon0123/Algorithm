#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<std::pair<int,int>>>edges(N + 1);
    std::vector<int> indegree(N + 1);
    while (M--) {
        int a, b, num;
        std::cin >> a >> b >> num;
        edges[b].push_back(std::make_pair(a,num));
        indegree[a]++;
    }

    
    std::vector<int> basicPart;
    std::queue<int> queue;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) { // i = 기본 부품
            queue.push(i);
            basicPart.push_back(i);
        }
    }
    std::vector<std::vector<int>> basic(N + 1, std::vector<int>( basicPart.size() ));

    for (int i = 0; i < basicPart.size(); i++) {
        basic[basicPart[i]][i] = 1;
    }

    while (!queue.empty()) {
        int now = queue.front();
        queue.pop();
        for (std::pair<int,int> next : edges[now]) {
            indegree[next.first]--;

            for (int i = 0; i < basicPart.size(); i++) {
                basic[next.first][i] += basic[now][i] * next.second;
            }
            if (indegree[next.first] == 0) {
                queue.push(next.first);
            }
        }
    }

    for (int i = 0; i < basicPart.size(); i++) {
        std::cout << basicPart[i] << ' ' << basic[N][i] << '\n';
    }
}