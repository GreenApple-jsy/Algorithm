#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> answer_list;
vector <vector <int>> possible_numbers;

void make_list(int num, vector <bool> check) { //banned_id가 될 수 있는 아이디들의 조합 만들기
	if (num >= possible_numbers.size()) {
		string s = "";
		for (int i = 0; i < check.size(); i++) {
			if (check[i]) {
				s += to_string(i);
			}
		}
		for (int i = 0; i < answer_list.size(); i++) {
			if (answer_list[i] == s) {
				return;
			}
		}
		answer_list.push_back(s);
		return;
	}

	for (int i = 0; i < possible_numbers[num].size(); i++) {
		if (check[possible_numbers[num][i]] == false) {
			check[possible_numbers[num][i]] = true;
			make_list(num + 1, check);
			check[possible_numbers[num][i]] = false;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int pos = 0;
	int shorter_length = 0;
	vector <bool> check;

	check.assign(user_id.size(), false);
	possible_numbers.resize(banned_id.size());

	for (int i = 0; i < banned_id.size(); i++) {
		for (int j = 0; j < user_id.size(); j++) {
			shorter_length = banned_id[i].length() < user_id[j].length() ? banned_id[i].length() : user_id[j].length();
			for (pos = 0; pos < shorter_length; pos++) {
				if ((banned_id[i][pos] != '*') && (user_id[j][pos] != banned_id[i][pos])) {
					break;
				}
			}
			if ((pos >= shorter_length) && (banned_id[i].length() == user_id[j].length())) { //각 banned_id가 될 수 있는 아이디 찾기
				possible_numbers[i].push_back(j);
			}
		}
	}
	make_list(0, check);
	return answer_list.size();
}