#include <iostream>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;

    long long arr[100] = { 1,1,1,2,2,3,4,5,7,9, };

    for (int i = 10; i < 100; ++i)
    {
        arr[i] = arr[i - 1] + arr[i - 5];
    }

    int n;
    while (t--)
    {
        std::cin >> n;
        std::cout << arr[n - 1] << "\n";
    }

}