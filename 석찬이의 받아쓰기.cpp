#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int TC, N, answer;
	char A[100000], B[100000];
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> N >> A >> B;
		answer = N;
		for (int j = 0; j < N; j++) {
			if (A[j] != B[j])
				answer--;
		}
		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}
