#include <string>
#include <iostream>
using namespace std;

int main() {
	string answer;
	int T, N, sum, current, addN, temp = 0;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		current = N / 2;
		sum = 0;
		addN = -1;
		for (int j = 0; j < N; j++) {
			for (int k = 1; k <= N; k++) {
				scanf("%1d", &temp);
				if ((k > current) && (k <= N - current))
					sum += temp;
			}
			if (current == 0)
				addN = 1;
			current += addN;
		}
		answer += "#" + to_string(i) + " " + to_string(sum) + "\n";
	}
	cout << answer;
	return 0;
}
