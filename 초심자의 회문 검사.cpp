#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		bool is_palindrome = true;
		string S;
		cin >> S;
		int sSize = S.length();
		for (int j = 0; j <= sSize / 2; j++) {
			if (S[j] != S[sSize - j - 1]) {
				is_palindrome = false;
				break;
			}
		}
		cout << "#" << i << " " << is_palindrome << endl;
	}
	return 0;
}
