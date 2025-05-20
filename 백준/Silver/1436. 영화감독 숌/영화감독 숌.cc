#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	int num = 665;
	int cnt = 0;
	std::string str;

	while(true)
	{
		++num;
		str = std::to_string(num);
		if (str.find("666") == -1)
		{
			continue;
		}
		++cnt;
		if (cnt == N)
		{
			std::cout << num;
			break;
		}
	}
}