#include <iostream>
#include <vector>

int N;
std::vector<int> primeNumbers;
int oneDigit[4] = { 1,3,7,9 };
int oneDigitPrimeNumbers[4] = { 2,3,5,7 };

void findPrimeNumbers(int number, int digit){
	for (int i = 2; i*i < number ; ++i) {
		if (number % i == 0) {
			return;
		}
	}
	if (digit == N) { 
		primeNumbers.push_back(number);
		return; 
	}
	for (int i : oneDigit) {
		findPrimeNumbers(number * 10 + i, digit+1);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i : oneDigitPrimeNumbers) {
		findPrimeNumbers(i,1);
	}
	for (int i : primeNumbers) {
		std::cout << i << '\n';
	}
}