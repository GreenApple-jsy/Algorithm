#include <string>
#include <iostream>
using namespace std;

int main() {
	int T, a, b, c;
	string answer;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> a >> b >> c;
		if (a == b)
			answer += "#" + to_string(i) + " " + to_string(c) + "\n";
		else if (a == c)
			answer += "#" + to_string(i) + " " + to_string(b) + "\n";
		else if (b == c)
			answer += "#" + to_string(i) + " " + to_string(a) + "\n";
	}
	cout << answer;
	return 0;
}
