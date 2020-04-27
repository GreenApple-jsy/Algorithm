#include <string>
#include <vector>
using namespace std;

int answer;

void func(long &num) {
	if (num % 2 == 0)
		num /= 2;
	else
		num = (num * 3) + 1;
}

int solution(int num) {
	long t = num;
	answer = 0;
	while (t != 1) {
		func(t);
		answer++;
		if (answer > 500)
			return -1;
	}
	return answer;
}