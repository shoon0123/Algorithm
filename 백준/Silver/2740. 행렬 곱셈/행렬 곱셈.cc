#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, K;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> A[i][j];
        }
    }

    std::cin >> M >> K;

    std::vector<std::vector<int>> B(M, std::vector<int>(K));
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            std::cin >> B[i][j];
        }
    }

    std::vector<std::vector<int>> C(N, std::vector<int>(K, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            std::cout << C[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}