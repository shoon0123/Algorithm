#include <iostream>
#include <limits.h>
static int N, M;
static long mdistance[101][101];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) {
                mdistance[i][j] = 0;
            }
            else {
                mdistance[i][j] = INT_MAX/2;
            }
        }
    }
    for (int i = 0; i < M; ++i) {
        int s, e, v;
        std::cin >> s >> e >> v;
        if (mdistance[s][e] > v) {
            mdistance[s][e] = v;
        }
    }
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (mdistance[i][j] > mdistance[i][k] + mdistance[k][j]) {
                    mdistance[i][j] = mdistance[i][k] + mdistance[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (mdistance[i][j] == INT_MAX/2) {
                std::cout << "0 ";
            }
            else {
                std::cout << mdistance[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
}