#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//두 프렌즈 간의 거리 구하기
int checkDistance(vector<char> &friends, char friend_one, char friend_two) {
	int p, q;
	for (int i = 0; i < friends.size(); i++) { //앞쪽에 위치한 프렌드 위치 찾기
		if ((friends[i] == friend_one) || (friends[i] == friend_two)) {
			p = i;
			break;
		}
	}
	for (int i = friends.size() - 1; i >= 0; i--) { //뒤쪽에 위치한 프렌드 위치 찾기
		if ((friends[i] == friend_one) || (friends[i] == friend_two)) {
			q = i;
			break;
		}
	}
	return (abs(p - q) - 1);
}

int solution(int n, vector<string> data) {
	vector<char> friends = { 'A','C','F','J','M','N','R','T' };
	int answer = 0;
	int distance, wanted_distance;
	do {
		answer++;
		for (int i = 0; i < n; i++) {
			distance = checkDistance(friends, data[i][0], data[i][2]); //두 프렌즈 간의 거리
			wanted_distance = atoi((data[i].substr(4, data[i].length())).c_str()); //원하는 거리 조건
			if (data[i][3] == '=') {
				if (distance != wanted_distance) {
					answer--;
					break;
				}	
			}
			else if (data[i][3] == '<') {
				if (distance >= wanted_distance) {
					answer--;
					break;
				}	
			}
			else if (data[i][3] == '>') {
				if (distance <= wanted_distance) {
					answer--;
					break;
				}
			}
		}
	} while (next_permutation(friends.begin(), friends.end()));
	return answer;
}
