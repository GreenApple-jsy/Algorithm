#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector <string> answer;
	vector <string> uid; //record���� ���̵� ���� ����
	map <string, string> nick_Info; //key:���̵� / value:�г���
	stringstream ss; string action; string id; string nickname;
	for (int i = 0; i < record.size(); i++) {
		ss.str(record[i]);
		ss >> action; //Enter, Leave, Change
		if (action == "Enter") {
			ss >> id;
			ss >> nickname;
			answer.push_back("���� ���Խ��ϴ�.");
			uid.push_back(id);
			nick_Info[id] = nickname;
		}
		else if (action == "Leave") {
			ss >> id;
			answer.push_back("���� �������ϴ�.");
			uid.push_back(id);
		}
		else {
			ss >> id;
			ss >> nickname;
			nick_Info[id] = nickname;
		}
		ss.clear();
	}
	for (int i = 0; i < answer.size(); i++) {
		answer[i] = nick_Info[uid[i]] + answer[i]; //���̵� �ش��ϴ� �г����� �ٿ���
	}
	return answer;
}