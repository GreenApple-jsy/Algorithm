#include <string>
#include <vector>
using namespace std;

string solution(string s) {
	string answer = "";
	bool IsEven = true; //짝수번째 알파벳일 경우 TRUE
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') { //공백일 경우
			answer += s[i];
			IsEven = true;
		}
		else if (isalpha(s[i])) {
			if (IsEven)
				answer += toupper(s[i]); //짝수번째 알파벳인 경우 대문자 처리
			else
				answer += tolower(s[i]); //홀수번째 알파벳인 경우 소문자 처리
			IsEven = !IsEven;
		}
		else { //기타 문자인 경우
			answer += s[i];
		}
	}
	return answer;
}
