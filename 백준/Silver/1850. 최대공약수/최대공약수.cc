#include <iostream>
#include <string>

long GCD(long A, long B) {
    return B ? GCD(B, A % B) : A;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    long A,B;
    std::cin >> A >> B;
    std::cout << std::string(GCD(A, B),'1');
}