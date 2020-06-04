#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	string S, temp, answer;
	vector <char> keypad = { 'Z', 'c', 'f', 'i', 'l', 'o', 's', 'v', 'z' };
	int T, N, sum, check;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		sum = 0;
		cin >> S >> N;
		for (int j = 0; j < N; j++) {
			check = 0;
			cin >> temp;
			if (temp.length() != S.length())
				continue;
			for (int k = 0; k < temp.length(); k++) {
				if (((int)temp[k] > (int)keypad[S[k] - 50]) && (int)temp[k] <= (int)keypad[S[k] - 49])
					check++;
			}
			if (check == S.length())
				sum++;
		}
		answer += "#" + to_string(i) + " " + to_string(sum) + "\n";
	}
	cout << answer;
	return 0;
}
