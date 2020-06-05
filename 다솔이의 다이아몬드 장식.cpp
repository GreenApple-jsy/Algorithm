#include <string>
#include <vector>
#include <iostream>
using namespace std;

string FirstAndFifthLine(int stringLength) {
	for (int i = 1; i <= ((5 * stringLength) - stringLength + 1); i++) {
		
	}
}

string ThirdLine(string inputString) {

}

string SecondAndFourthLine(int stringLength) {

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
