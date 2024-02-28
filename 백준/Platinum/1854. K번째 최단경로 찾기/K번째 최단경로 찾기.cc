#include <iostream>
#include <vector>
#include <queue>
#include<set>

typedef std::pair<int, int> edge;
static int N, M, K;
static std::vector<std::vector<edge>> edgeList;
static std::vector<std::multiset<int>> minDistance; //최소거리 K개까지 저장
static std::vector<int> visited; //K번까지 방문이 가능
static std::priority_queue<edge, std::vector<edge>, std::greater<edge>> queue;
// <현재거리, 현재노드> 우선순위큐 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M >> K;
    edgeList.resize(N + 1);
    minDistance.resize(N + 1);
    visited.resize(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int start, end, cost;
        std::cin >> start >> end >> cost;
        edgeList[start].push_back(std::make_pair(end, cost));
    }
    queue.push(std::make_pair(0, 1));
    minDistance[1].insert(0);

    while (!queue.empty()) {
        edge current = queue.top();
        queue.pop();
        int currentDistance = current.first;
        int currentCity = current.second;
        if (visited[currentCity] >= K) {
            continue;
        }
        visited[currentCity]++;
        for (const edge& next : edgeList[currentCity]) {
            int nextCity = next.first;
            int distance = next.second;
            int nextDistance = currentDistance + distance;
            if (minDistance[nextCity].size() < K) {
                minDistance[nextCity].insert(nextDistance);
                queue.push(std::make_pair(nextDistance, nextCity));
            }
            else if (*minDistance[nextCity].rbegin() > nextDistance) {
                minDistance[nextCity].insert(nextDistance);
                minDistance[nextCity].erase(std::prev(minDistance[nextCity].end()));
                queue.push(std::make_pair(nextDistance, nextCity));
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        minDistance[i].size() == K 
            ? std::cout << *minDistance[i].rbegin() << '\n'
            : std::cout << -1 << '\n';
    }
}