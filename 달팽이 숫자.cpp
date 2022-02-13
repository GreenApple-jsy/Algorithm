#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>>Dir = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; //오른쪽, 아래, 왼쪽, 위
	vector<vector<int>>Board(10, vector<int>(10)); //-1로 초기화된 배열
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j)
			Board[i][j] = -1;
	}

	int tc, N, i, cur_Dir, x, y;
	cin >> tc;
	for (int t = 1; t <= tc; ++t) {
		vector<vector<int>>temp = Board;

		cur_Dir = 0; //현재 진행 방향
		x = 0; y = 0; //현재 좌표

		cin >> N;
		for (i = 1; i <= (N * N); ++i) {
			temp[x][y] = i;

			//좌표 범위(0 ~ N - 1)를 넘었거나 이미 칸이 채워진 경우 진행방향을 바꿈
			if (x + Dir[cur_Dir][0] > N - 1 || x + Dir[cur_Dir][0] < 0 ||
				y + Dir[cur_Dir][1] > N - 1 || y + Dir[cur_Dir][1] < 0 ||
				temp[x + Dir[cur_Dir][0]][y + Dir[cur_Dir][1]] != -1) {
				cur_Dir++;

				if (cur_Dir >= 4)
					cur_Dir = 0;
			}
			x += Dir[cur_Dir][0];
			y += Dir[cur_Dir][1];
		}

		cout << "#" << t << endl;
		for (int m = 0; m < N; ++m) {
			for (int n = 0; n < N; ++n)
				cout << temp[m][n] << " ";
			cout << '\n';
		}
	}
}
