#include <iostream>
#include <string>
#include <set>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	std::cin >> n;
	std::set<std::string> strSet;
	std::string str;
	int count = 0;
	while (n--)
	{
		std::cin >> str;
		if (str == "ENTER")
		{
			strSet.clear();
		}
		else if (strSet.find(str) == strSet.end())
		{
			++count;
			strSet.insert(str);
		}
	}
	std::cout << count;
}