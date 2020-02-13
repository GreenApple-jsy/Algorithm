#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//두 문자를 이어붙였을 때, 더 큰 값이 되는 방향으로 sort
bool cmp(const string &a, const string &b) {
	return ((a + b) > (b + a));
}

string solution(vector<int> numbers) {
	vector<string> str_vec;
	string answer = "";
	for (int i = 0; i < numbers.size(); i++) {
		str_vec.push_back(to_string(numbers[i]));
	}
	sort(str_vec.begin(), str_vec.end(), cmp);
	for (int i = 0; i < str_vec.size(); i++) {
		answer += str_vec[i];
	}
	//numbers 요소가 0들로만 이루어져 있을 경우 0을 리턴
	if (answer.front() == '0')
		return "0";
	return answer;
}