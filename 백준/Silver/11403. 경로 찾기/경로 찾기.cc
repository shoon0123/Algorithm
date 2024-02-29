#include <iostream>

static int N;
static int mdistance[101][101];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            std::cin >> mdistance[i][j];
        }
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (mdistance[i][k] && mdistance[k][j]) {
                    mdistance[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
             std::cout << mdistance[i][j] << " ";
        }
        std::cout << "\n";
    }
}