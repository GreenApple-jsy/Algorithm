#include <string>
#include <vector>
#include <iostream>
using namespace std;

string FirstAndFifthLine(int stringLength) {
	string s;
	for (int i = 1; i <= ((5 * stringLength) - stringLength + 1); i++) {
		if ((i - 3) % 4 == 0)
			s += "#";
		else
			s += ".";
	}
	return s + "\n";
}

string ThirdLine(string inputString) {
	int stringLength = inputString.length();
	string s;
	int index = 0;
	for (int i = 1; i <= ((5 * stringLength) - stringLength + 1); i++) {
		if ((i - 1) % 4 == 0)
			s += "#";
		else if ((i - 3) % 4 == 0) {
			s += inputString[index];
			index++;
		}
		else
			s += ".";
	}
	return s + "\n";
}

string SecondAndFourthLine(int stringLength) {
	string s;
	for (int i = 1; i <= ((5 * stringLength) - stringLength + 1); i++) {
		if (i % 2 == 0)
			s += "#";
		else
			s += ".";
	}
	return s + "\n";
}

int main() {
	string inputString, answer, temp1, temp2;
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> inputString;
		temp1 = FirstAndFifthLine(inputString.length());
		temp2 = SecondAndFourthLine(inputString.length());
		answer += temp1 + temp2 + ThirdLine(inputString) + temp2 + temp1;
	}
	cout << answer;
	return 0;
}
