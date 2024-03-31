#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> vec(N, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    int count = 0;

    

    for (int k = 0; k < N; ++k) {
        int i = 0;
        int j = N - 1;
        while (i<j) {
            if (vec[i] + vec[j] < vec[k]) {
                ++i;
            }
            else if (vec[i] + vec[j] > vec[k]) {
                --j;
            }
            else {
                if (i != k && j != k)
                {
                    ++count;
                    break;
                }
                else if (i == k) {
                    ++i;
                }
                else if (j == k) {
                    --j;
                }
            }
        }
    }
    std::cout << count << "\n";
}
