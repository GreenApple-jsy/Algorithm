#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
	string answer = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') // 공백일 경우 그대로
			answer += " ";
		else {
			// 소문자, 대문자 범위 벗어난 경우
			if (((s[i] + n > 122)) || ((s[i] < 91) && (s[i] + n >= 91)))
				answer += (s[i] + n - 26);
			else
				answer += (s[i] + n);
		}
	}
	return answer;
}
