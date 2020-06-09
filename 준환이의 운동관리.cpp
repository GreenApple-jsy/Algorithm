#include <string>
#include <iostream>
using namespace std;

int main() {
	string answer;
	int T, L, U, X;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> L >> U >> X;
		if (X > U)
			answer += "#" + to_string(i) + " -1\n";
		else if (X < L)
			answer += "#" + to_string(i) + " " + to_string(L - X) + "\n";
		else
			answer += "#" + to_string(i) + " 0\n";
	}
	cout << answer;
	return 0;
}
