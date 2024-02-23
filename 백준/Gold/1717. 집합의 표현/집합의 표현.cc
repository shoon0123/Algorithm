#include <iostream>
#include <vector>

static std::vector<int>parent;

int findParent(int a) {
    return a == parent[a] ? a : parent[a] = findParent(parent[a]);
}

void unionfunc(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b) {
        parent[b] = a;
    }
}

bool isSameUnion(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    return a == b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    parent.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }
    while (m--) {
        int q, a, b;
        std::cin >> q >> a >> b;
        if (q) {
            isSameUnion(a, b) ?
                std::cout << "YES" << '\n' :
                std::cout << "NO" << '\n';
        }
        else {
            unionfunc(a, b);
        }
    }
}