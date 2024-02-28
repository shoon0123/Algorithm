#include <iostream>
#include <vector>
#include <queue>
#include<limits.h>

typedef std::pair<int, int> edge;
static int N, M;
static std::vector<std::vector<edge>> edgeList;
static std::vector<int> minCost;
static std::vector<bool> visited;
static std::priority_queue<edge,std::vector<edge>,std::greater<edge>> queue;


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;
    edgeList.resize(N + 1);
    minCost.resize(N + 1, INT_MAX);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int start, end, cost;
        std::cin >> start >> end >> cost;
        edgeList[start].push_back(std::make_pair(end, cost));
    }
    int startingPoint, destination;
    std::cin >> startingPoint >> destination;

    queue.push(std::make_pair(0,startingPoint));
    minCost[startingPoint] = 0;

    while (!queue.empty()) {
        edge current = queue.top();
        queue.pop();
        int currentCity = current.second;
        if (visited[currentCity]) {
            continue;
        }
        visited[currentCity] = true;
        for (const edge& next : edgeList[currentCity]) {
            int nextCity = next.first;
            int cost = next.second;
            if (minCost[nextCity] > minCost[currentCity] + cost) {
                minCost[nextCity] = minCost[currentCity] + cost;
                queue.push(std::make_pair(minCost[nextCity],nextCity));
            }
        }
    }

    std::cout << minCost[destination];
}