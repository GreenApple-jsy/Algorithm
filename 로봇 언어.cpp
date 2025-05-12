#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int T, sum, maxSum, qCount;
	string s;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> s;
		sum = 0, maxSum = 0, qCount = 0;
		for (int c = 0; c < s.length(); c++) {
			if (s[c] == 'L') {
				sum--;
			}
			else if (s[c] == 'R') {
				sum++;
			}
			else if (s[c] == '?') {
				qCount++;
			}
			maxSum = max(maxSum, max(abs(sum - qCount), abs(sum + qCount)));
		}
		cout << maxSum << endl;
	}
	return 0;
}
