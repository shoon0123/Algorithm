#include <iostream>
#include <vector>

static std::vector<int> parent;
static std::vector<int> trueP;
static std::vector<std::vector<int>> party;
static int result;
void unionfunc(int a, int b);
int find(int a);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M, T;
    std::cin >> N >> M >> T;
    trueP.resize(T);

    for (int i = 0; i < T; ++i) {
        std::cin >> trueP[i];
    }
    party.resize(M);

    for (int i = 0; i < M; ++i) {
        int party_size;
        std::cin >> party_size;

        for (int j = 0; j < party_size; ++j) {
            int temp;
            std::cin >> temp;
            party[i].push_back(temp);
        }
    }
    parent.resize(N + 1);

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++){
        int firstPeople = party[i][0];
        for (int j = 1; j < party[i].size(); j++) {
            unionfunc(firstPeople, party[i][j]);
        }
    }
    for (int i = 0; i < M; i++) {
        bool isPossible = true;
        int cur = party[i][0];
        for (int j = 0; j < T; j++) {
            if (find(cur) == find(trueP[j])) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) {
            result++;
        }
    }
    std::cout << result;
}

void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

int find(int a) {
    if (a == parent[a]) {
        return a;
    }
    else {
        return parent[a] = find(parent[a]);
    }
}