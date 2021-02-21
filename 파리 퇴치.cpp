#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, N, M, max_sum;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		max_sum = 0;
		cin >> N >> M;
		vector <vector<int>> board(N);
		for (int j = 0; j < N; j++) {
			board[j].resize(N);
			for (int k = 0; k < N; k++)
				cin >> board[j][k];
		}
		for (int j = 0; j <= N - M; j++) {
			for (int k = 0; k <= N - M; k++) {
				int sum = 0;
				for (int p = j; p < j + M; p++) {
					for (int q = k; q < k + M; q++)
						sum += board[p][q];
				}
				if (sum > max_sum)
					max_sum = sum;
			}
		}
		cout << "#" << i << " " << max_sum << endl;
	}
}
