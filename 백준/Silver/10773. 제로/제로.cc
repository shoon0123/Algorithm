#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int K;
    std::cin >> K;
    std::stack<int> st;

    int num, sum = 0;

    while (K--)
    {
        std::cin >> num;
        if (num == 0)
        {
            st.pop();
        }
        else
        {
            st.push(num);
        }
    }
    int stackSize = st.size();
    for (int i = 0; i < stackSize; ++i)
    {
        sum += st.top();
        st.pop();
    }
    std::cout << sum;
    
}