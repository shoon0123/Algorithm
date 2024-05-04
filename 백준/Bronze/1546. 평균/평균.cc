#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> scores;

    for (int i = 0, score; i < N; ++i) {
        std::cin >> score;
        scores.push_back(score);
    }
    int highScore = *max_element(scores.begin(), scores.end());
    double total= accumulate(scores.begin(), scores.end(), 0);
    
    std::cout << total/highScore*100/N << "\n";
}
