#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//양수는 내림차순, 음수는 오름차순으로 저장
//1의 개수만큼 sum에 더함
// 양수는 큰거끼리, 음수는 작은거끼리 묶음
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    std::priority_queue<int, std::vector<int>, std::less<int>> positiveNumbers;
    std::priority_queue<int, std::vector<int>, std::greater<int>> negativeNumbers;
    int sum = 0;
    int oneCount = 0;
    for (int i = 0; i < N; ++i) {
        int number;
        std::cin >> number;
        if (number == 1) {
            ++oneCount;
        }
        else if (number > 1) {
            positiveNumbers.push(number);
        }
        else {
            negativeNumbers.push(number);
        }
    }
    while (!negativeNumbers.empty()) {
        int tmp = negativeNumbers.top();
        negativeNumbers.pop();
        if (!negativeNumbers.empty()) {
            tmp *= negativeNumbers.top();
            negativeNumbers.pop();
            sum += tmp;
        }
        else {
            sum += tmp;
        }
    }
    while (!positiveNumbers.empty()) {
        int tmp = positiveNumbers.top();
        positiveNumbers.pop();
        if (!positiveNumbers.empty()) {
            tmp *= positiveNumbers.top();
            positiveNumbers.pop();
            sum += tmp;
        }
        else {
            sum += tmp;
        }
    }
    sum += oneCount;
    std::cout << sum;
}