#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
	vector <int> numbers;
	string temp = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			numbers.push_back(atoi(temp.c_str()));
			temp = "";
		}
		else {
			temp += s[i];
		}
	}
	numbers.push_back(atoi(temp.c_str()));
	sort(numbers.begin(), numbers.end());
	
	return to_string(numbers.front()) +" " + to_string(numbers.back());
}

int main() {
	cout << solution("4 3 2 1");
	system("pause");
}