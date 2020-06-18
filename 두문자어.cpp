#include <iostream>
#include <string>
using namespace std;

int main() {
	char c;
	int T;
	string input, answer = "";
	cin >> T;
	getline(cin, input);
	for (int i = 1; i <= T; i++) {
		answer += "#" + to_string(i) + " ";
		getline(cin, input);
		c = toupper(input[0]);
		for (int j = 1; j < input.length() - 1; j++) {
			if (input[j] == ' ') {
				answer += c;
				c = toupper(input[j + 1]);
			}	
		}
		answer += string(1,c) + "\n";
	}
	cout << answer;
	return 0;
}
