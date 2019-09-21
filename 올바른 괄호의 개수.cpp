#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
	int answer = 0;
	int sum = 0;
	vector <int> s;
	for (int i = 0; i < n; i++) {
		s.push_back(1); //왼 괄호의 값 1
		s.push_back(-1); //오른 괄호의 값 1
	}
	do {
		sum = 0;
		answer++;
		for (int i = 0; i < 2*n; i++) {
			sum += s[i];
			if (sum < 0) { //한 번이라도 오른 괄호가 왼 괄호보다 많아지면 틀린 괄호 표현이다
				answer--;
				break;
			}	
		}
	} while (next_permutation(s.begin(), s.end())); //만들 수 있는 괄호 조합
	return answer;
}
