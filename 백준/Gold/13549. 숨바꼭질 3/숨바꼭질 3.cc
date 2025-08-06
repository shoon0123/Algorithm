#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int MAX = 100001;
const int INF = std::numeric_limits<int>::max();

int main()
{
    int start, target;
    std::cin >> start >> target;

    std::vector<int> dist(MAX, INF);
    dist[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    pq.push({ 0, start });

    while (!pq.empty())
    {
        int currentCost = pq.top().first;
        int currentPos = pq.top().second;
        pq.pop();

        if (dist[currentPos] < currentCost)
        {
            continue;
        }

        int nextPos = currentPos * 2;
        if (nextPos < MAX && dist[nextPos] > currentCost)
        {
            dist[nextPos] = currentCost;
            pq.push({ currentCost, nextPos });
        }

        nextPos = currentPos + 1;
        if (nextPos < MAX && dist[nextPos] > currentCost + 1)
        {
            dist[nextPos] = currentCost + 1;
            pq.push({ currentCost + 1, nextPos });
        }

        nextPos = currentPos - 1;
        if (nextPos >= 0 && dist[nextPos] > currentCost + 1)
        {
            dist[nextPos] = currentCost + 1;
            pq.push({ currentCost + 1, nextPos });
        }
    }

    std::cout << dist[target] << '\n';
    return 0;
}
