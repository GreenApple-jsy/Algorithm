#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;
	if (n > s) //집합을 만들 수 없는 경우
		answer.push_back(-1);
	else {
		int div = s / n;
		int diff = s % n;
		int pos = n - 1;
		answer.assign(n, div); //  합을 원소개수로 나눈 몫으로 집합을 먼저 채움
		for (int i = diff; i > 0; i--)  //나머지를 위해 집합의 마지막 원소부터 순차적으로 1을 더해줌
			answer[pos--]++;
	}
	return answer;
}