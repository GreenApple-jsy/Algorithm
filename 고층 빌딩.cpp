#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, L, R;
	cin >> N >> L >> R;

	//st[i][j][k]는 N개의 막대를 배치했을 때 왼쪽에서 L개, 오른쪽에서 R개가 보이는 총 경우의 수
	vector<vector<vector<unsigned long long> > > st(N + 1, vector <vector<unsigned long long> >(N + 1, vector<unsigned long long>(N + 1, 0)));
	st[1][1][1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= L; ++j) {
			for (int k = 1; k <= R; ++k) {
				st[i][j][k] += st[i - 1][j - 1][k];
				st[i][j][k] += st[i - 1][j][k - 1];
				st[i][j][k] += (st[i - 1][j][k] * ((long long)i - 2));
				st[i][j][k] %= 1000000007;
			}
		}
	}
	cout << (st[N][L][R] % 1000000007) << endl;
	return 0;
}
