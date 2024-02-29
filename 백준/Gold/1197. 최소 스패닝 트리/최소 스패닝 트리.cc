#include <iostream>
#include <queue>
#include <tuple>

void unionFunc(int a, int b);
int find(int a);
static std::vector<int> parent;
typedef std::tuple<int, int, int> Edge;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

    parent.resize(N + 1);

    for (int i = 0; i <= N; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < M; ++i) {
        int s, e, v;
        std::cin >> s >> e >> v;
        pq.push(Edge{ v, s, e });
    }

    int useEdge = 0;
    int result = 0;

    while (useEdge < N - 1) {
        Edge now = pq.top();
        const int& v = std::get<0>(now);
        const int& s = std::get<1>(now);
        const int& e = std::get<2>(now);
        pq.pop();
        if (find(s) != find(e)) {
            unionFunc(s, e);
            result = result + v;
            ++useEdge;
        }
    }
    std::cout << result;
}

void unionFunc(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

int find(int a) {
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}