#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	unordered_map<string, int> dic;
	unordered_map<string, int>::iterator iter;
	int string_size;

	for (int i = 1; i <= 26; i++) //사전 초기화
		dic.insert(unordered_map<string, int>::value_type(string(1, (char)i + 64), i));

	for (int i = 0; i < msg.length(); i++) {
		string_size = 1;

		//입력과 일치하는 가장 긴 문자열 찾기
		do {
			string_size++;
			iter = dic.find(msg.substr(i, string_size));
		} while ((iter != dic.end()) && (i + string_size <= msg.length()));
		
		//찾은 문자열의 색인 번호 출력(저장)
		answer.push_back(dic[msg.substr(i, string_size - 1)]);

		//입력에서 처리되지 않은 다음 글자가 남아있다면 사전에 등록
		if (i + string_size < msg.length())
			dic.insert(unordered_map<string, int>::value_type(msg.substr(i, string_size), dic.size() + 1));
			
		//찾은 문자열의 끝 위치로 건너뛰기
		i = i + string_size - 2;
	}
	return answer;
}
