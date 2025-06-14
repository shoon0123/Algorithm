#include <iostream>
#include <string>
#include <map>

int Factorial(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return Factorial(n - 1)* n;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	std::cin >> n;
	if (n == 0)
	{
		std::cout << 1;
		return 0;
	}
	std::cout << Factorial(n);

}