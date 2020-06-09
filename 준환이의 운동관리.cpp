#include <string>
#include <iostream>
using namespace std;

//1주일에 L분 이상 U분 이하의 운동

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
