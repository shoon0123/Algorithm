#include <iostream>
#include <queue>

int main()
{

    int N;

    std::cin >> N ;
    std::queue<int> myQueue;


    for (int i = 1; i <= N; ++i) {
        myQueue.push(i);
    }

    while (myQueue.size() > 1) {
        myQueue.pop();
        myQueue.push(myQueue.front());
        myQueue.pop();
    }
    
    std::cout << myQueue.front() <<'\n';
}