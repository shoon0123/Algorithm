#include <iostream>
#include <vector>
#include <string>

long long combination(int n, int r) {
    r = r < n - r ? r : n - r;
    long long temp = 1;
    for (int i = 1; i <= r; ++i) {
        temp *= n + 1 - i;
        temp /= i;
        if (temp > 1000000000) {
            return 1000000001;
        }
    }
    return temp;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    long long K;
    std::cin >> N >> M >> K;
    if (K > combination(N + M, N)) {
        std::cout << -1;
        return 0;
    }
    
    int sum = N + M;
    int n = N;
    int m = M;
    std::string answer(sum,'o');

    for (int i = 0; i < N+M; ++i) {
        if (n == 0) {
            answer[i] = 'z';
            continue;
        }
        else if(m==0){
            answer[i] = 'a';
            continue;
        }
        long long com = combination(sum - 1, n - 1);
        bool isA = com >= K ;
        if (isA) {
            answer[i] = 'a';
            sum--;
            n--;
        }
        else {
            answer[i] = 'z';
            sum--;
            m--;
            K -= com;
        }
    }

    std::cout << answer;
}