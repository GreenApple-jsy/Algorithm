#include <string>
#include <vector>
#include <iostream>
using namespace std;

//1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
string step_one(string id) {
	string s = "";
	for (int i = 0; i < id.length(); i++) {
		s += tolower(id[i]);
	}
	cout << "1단계 " << s << endl;
	return s;
}

//2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
string step_two(string id) {
	string s = "";
	for (int i = 0; i < id.length(); i++) {
		if (isalpha(id[i]) || isdigit(id[i]) || id[i] == '-' || id[i] == '_' || id[i] == '.')
			s += id[i];
	}
	cout << "2단계 " << s << endl;
	return s;
}

//3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
string step_three(string id) {
	string s = "";
	int start_point = 0;
	for (int i = 0; i < id.length(); i++) {
		if (id[i] == '.' && i < id.length() - 1 && id[i+1] == '.') {
			s += id.substr(start_point, i - start_point + 1);
			while (i < id.length() && id[i] == '.')
				i++;
			start_point = i;
		}
	}
	s += id.substr(start_point, id.length() - start_point + 1);
	cout << "3단계 " << s << endl;
	return s;
}

//4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
string step_four(string id) {
	string s = id;
	if (s.length() >= 1 && s.front() == '.')
		s = s.substr(1, s.length());
	if (s.length() >= 1 && s.back() == '.')
		s = s.substr(0, s.length() - 1);
	cout << "4단계 " << s << endl;
	return s;
}

//5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
string step_five(string id) {
	string s = id;
	if (s.length() == 0)
		s = "a";
	cout << "5단계 " << s << endl;
	return s;
}

//6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
string step_six(string id) {
	string s = id;
	if (id.length() >= 16)
		s = id.substr(0, 15);
	if (s.back() == '.')
		s = s.substr(0, 14);
	cout << "6단계 " << s << endl;
	return s;
}

//7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
string step_seven(string id) {
	string s = id;
	if (s.length() <= 2) {
		while (s.length() < 3)
			s += s.back();
	}
	cout << "7단계 " << s << endl;
	return s;
}

string solution(string new_id) {
	string answer = step_one(new_id);
	answer = step_two(answer);
	answer = step_three(answer);
	answer = step_four(answer);
	answer = step_five(answer);
	answer = step_six(answer);
	answer = step_seven(answer);
	return answer;
}
