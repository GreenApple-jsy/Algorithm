#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int N, val = 0, answer = 0;
		cin >> N;
		vector <int> earnings(N);
		for (int j = 0; j < N; j++) {
			cin >> earnings[j];
			val += earnings[j];
		}
		val /= N;
		for (int j = 0; j < N; j++) {
			if (earnings[j] <= val)
				answer++;
		}
		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}
