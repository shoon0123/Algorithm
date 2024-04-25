#include <iostream>
#include <vector>
#include <stack>

long getLargestRectangle(std::vector<long>& h);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    while (true) {
        std::cin >> N;
        if (N == 0) { return 0; }
        std::vector<long> h(N, 0);
        for (int i = 0; i < N; ++i) {
            std::cin >> h[i];
        }
        std::cout << getLargestRectangle(h) << '\n';
    }
}

long getLargestRectangle(std::vector<long>& h)
{
    std::stack<std::pair<long,int>> stack;
    long largest = 0;
    for (int i = 0; i < h.size(); ++i) {
        int tmp = 0;
        while (true) {
            if (stack.empty()) {
                stack.push(std::make_pair(h[i], tmp + 1));
                break;
            }
            else if (h[i] < stack.top().first) {
                stack.top().second += tmp;
                long rectangle = stack.top().first * stack.top().second;
                if (largest < rectangle) {
                    largest = rectangle;
                }
                tmp = stack.top().second;
                stack.pop();
                continue;
            }
            else if (h[i] == stack.top().first) {
                stack.top().second += tmp + 1 ;
                break;
            }
            else {
                stack.push(std::make_pair(h[i], tmp+1));
                break;
            }
        }
    }
    int tmp = 0;
    while(!stack.empty()) {
        stack.top().second += tmp;
        long rectangle = stack.top().first * stack.top().second; 
        if (largest < rectangle) {
            largest = rectangle;
        }
        tmp = stack.top().second;
        stack.pop();
    }
    return largest;
}