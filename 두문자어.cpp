#include <iostream>
#include <string>
using namespace std;

int main() {
	char c;
	int T;
	string input, answer = "";
	cin >> T;
	getline(cin, input); //줄바꿈 문자 무시
	for (int i = 1; i <= T; i++) {
		answer += "#" + to_string(i) + " ";
		getline(cin, input); //한줄 문자열 입력받기
		c = toupper(input[0]);
		for (int j = 1; j < input.length() - 1; j++) {
			if (input[j] == ' ') {
				answer += c;
				c = toupper(input[j + 1]); //단어의 첫문자를 대문자로 변환하여 저장
			}	
		}
		answer += string(1,c) + "\n";
	}
	cout << answer;
	return 0;
}
