#include <iostream>
#include <limits.h>
static int N, M;
static int mdistance[101][101];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    const int MAX = INT_MAX / 2;
    std::cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            mdistance[i][j] = (i == j) ? 0 : MAX;
        }
    }
    
    for (int i = 1; i <= M; ++i) {
        int start, end;
        std::cin >> start >> end;
        mdistance[start][end] = 1;
        mdistance[end][start] = 1;
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (mdistance[i][j] > mdistance[i][k]+ mdistance[k][j]) {
                    mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
                }
            }
        }
    }
    int min = MAX;
    int idx = -1;
    int tmp;
    for (int i = 1; i <= N; ++i) {
        tmp = 0;
        for (int j = 1; j <= N; ++j) {
            tmp += mdistance[i][j];
        }
        if (tmp < min) {
            min = tmp;
            idx = i;
        }
    }
    std::cout << idx;
}