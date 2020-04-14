#include <string>
#include <vector>
using namespace std;

int solution(string arrangement) {
	int answer = 0; //쇠막대기 수 + 커팅 횟수
	int currentStickN = 0; //레이저가 자르게 될 쇠막대기 수
	for (int i = 0; i < arrangement.length() - 1; i++) {
		if (arrangement[i] == '(') {
			if (arrangement[i + 1] == ')') { //레이저인 경우
				answer += currentStickN;
			}
			else { //쇠막대기 시작 위치인 경우
				answer++;
				currentStickN++;
			}
		}
		else if ((arrangement[i] == ')') && (arrangement[i - 1] == ')')) { //쇠막대기 끝나는 위치인 경우
			currentStickN--;
		}
	}
	return answer;
}
