#include <iostream>
#include <vector>
#include <stack>

bool isPalindrome(int number);

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	const int MAX = 1003001;
	std::vector<int> numbers(MAX+1, 0);

	for (int i = 2; i <= MAX; ++i) {
		numbers[i] = i;
	}

	for (int i = 2; i*i <= MAX; ++i) {
		if (numbers[i] != 0) {
			for (int j = 2; i * j <= MAX; ++j) {
				numbers[i * j] = 0;
			}
		}
	}
	
	for (int i = N; i <= MAX; ++i) {
		if (numbers[i] != 0) {
			if (isPalindrome(numbers[i])) {
				std::cout<<numbers[i];
				return 0;
			}
		}
	}
}

bool isPalindrome(int number) {
	std::vector<int> vec;
	while (number!=0) {
		int n = number % 10;
		number /= 10;
		vec.push_back(n);
	}
	int start = 0;
	int end = vec.size()-1;
	while (start < end) {
		if (vec[start] != vec[end]) {
			return false;
		}
		++start;
		--end;
	}
	return true;
}