#include <string>
#include <iostream>
using namespace std;

int main() {
	int angle, T;
	string answer = "";
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> angle;
		answer += "#" + to_string(i) + " " + to_string(angle / 30) + " " + to_string(angle % 30 * 2) + "\n";
	}
	cout << answer;
	return 0;
}
