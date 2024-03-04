#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int N, M;
	std::cin >> N >> M;
	std::unordered_set<std::string> set;
	while (N--)
	{
		std::string str;
		std::cin >> str;
		set.insert(str);
	}
	int count = 0;
	while (M--)
	{
		std::string str;
		std::cin >> str;
		if (set.find(str) != set.end())
		{
			++count;
		}
	}
	std::cout << count;
}