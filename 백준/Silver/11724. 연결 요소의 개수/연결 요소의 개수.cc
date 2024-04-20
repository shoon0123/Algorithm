#include <iostream>
#include <vector>
#include <stack>

static std::vector<bool> visited;

void depthFirstSearch(std::vector<std::vector<int>>& edges, int node);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, E;
    std::cin >> N >> E;
    
    std::vector<std::vector<int>> edges(N);
    visited = std::vector<bool>(N, false);
    
    int answer= 0;

    for(int i = 0; i < E ; ++i)  {
        int start, end;
        std::cin >> start >> end;
        edges[start - 1].push_back(end - 1);
        edges[end - 1].push_back(start - 1);
    }

    for (int i = 0; i < N; ++i) {
        if (visited[i] == true) {
            continue;
        }
        else {
            depthFirstSearch(edges, i);
            ++answer;
        }
    }
    std::cout << answer;
}

void depthFirstSearch(std::vector<std::vector<int>>& edges, int node)
{
    if (visited[node]) {
        return;
    }
    visited[node] = true;
    for (int i = 0; i < edges[node].size(); ++i) {
        depthFirstSearch(edges, edges[node][i]);
    }
}