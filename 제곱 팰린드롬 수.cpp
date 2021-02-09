#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(int n) {
	string s = to_string(n);
	int start = 0, end = s.length() - 1, val = 0;
	while (start + val < end - val) {
		if (s[start] != s[end])
			return false;
		val++;
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int A, B, answer = 0;
		cin >> A >> B;
		for (int j = ceil(sqrt(A)); j <= floor(sqrt(B)); j++) {
			if (is_palindrome(j) && is_palindrome(pow(j, 2)))
				answer++;
		}
		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}
