#include <string>
#include <vector>
using namespace std;

bool solution(int x) {
	int sum = 0;
	int t = x;
	while (t >= 10) {
		sum += t % 10; //각 자리수 더하기
		t /= 10;
	}
	sum += t;
	if (x % sum == 0)
		return true;
	else
		return false;
}
