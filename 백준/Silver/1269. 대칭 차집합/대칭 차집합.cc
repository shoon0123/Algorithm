#include <iostream>
#include <set>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int ASize, BSize;
	std::cin >> ASize >> BSize;
	int count = 0;
	int num;
	if (ASize > BSize)
	{
		std::vector<int> A(ASize);
		std::set<int> B;

		for (int i = 0; i < ASize; ++i)
		{
			std::cin >> A[i];
		}
		for (int i = 0; i < BSize; ++i)
		{
			std::cin >> num;
			B.insert(num);
		}

		for (int i = 0; i < ASize; ++i)
		{
			if (B.find(A[i]) != B.end())
			{
				++count;
			}
		}
	}
	else
	{
		std::vector<int> B(BSize);
		std::set<int> A;

		for (int i = 0; i < ASize; ++i)
		{
			std::cin >> num;
			A.insert(num);
		}
		for (int i = 0; i < BSize; ++i)
		{
			std::cin >> B[i];
		}

		for (int i = 0; i < BSize; ++i)
		{
			if (A.find(B[i]) != A.end())
			{
				++count;
			}
		}
	}

	std::cout << ASize + BSize - 2*count;

}