#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
	if (sqrt(n) - (int)sqrt(n) == 0) // n이 정수의 제곱인 경우
		return (sqrt(n) + 1) * (sqrt(n) + 1);
	return -1;
}
