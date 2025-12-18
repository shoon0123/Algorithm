#include <iostream>
#include <vector>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;

    std::cin >> N ;
    std::vector<int> A(N);
    std::vector<char> resultV;


    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    
    std::stack<int> myStack;
    int num = 1;
    bool result = true;

    for (int i = 0; i < N; ++i) {
        int su = A[i];

        if (su >= num) {
            while (su >= num) {
                myStack.push(num++);
                resultV.push_back('+');

            }
            myStack.pop();
            resultV.push_back('-');
        }
        else {
            int n = myStack.top();
            myStack.pop();
            if (n > su) {
                std::cout << "NO";
                result = false;
                break;
            }
            else {
                resultV.push_back('-');
            }
        }
    }
    if (result) {
        for(int i = 0; i < resultV.size(); i++){
            std::cout << resultV[i] << '\n';
        }
    }
}
