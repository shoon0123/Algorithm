#include <iostream>
#include <vector>

int main()
{
    int k, n;
    std::cin >> k >> n;

    std::vector<long long> cables(k);
    long long maxLength = 0;

    for (int i = 0; i < k; ++i)
    {
        std::cin >> cables[i];
        if (cables[i] > maxLength)
        {
            maxLength = cables[i];
        }
    }

    long long left = 1;
    long long right = maxLength;
    long long answer = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        long long count = 0;
        for (int i = 0; i < k; ++i)
        {
            count += cables[i] / mid;
        }

        if (count >= n)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    std::cout << answer << '\n';

    return 0;
}
