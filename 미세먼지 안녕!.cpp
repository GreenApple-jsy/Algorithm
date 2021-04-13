#include <iostream>
#include <vector>
using namespace std;

int R, C;
int Ar; //공기청정기 위치(윗 행)
vector <vector<int>> board;
vector <vector<int>> diff_check; //확산되는 미세먼지 계산을 위한 벡터 형식
 
void diffuse() {
	vector <vector<int>> diffCheck = diff_check;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			//미세먼지 양이 5이상인 경우에만 계산 필요
			if (board[i][j] < 5)
				continue;

			int diff_count = 0;

			//왼쪽으로 확산 가능한 경우
			if ((j > 0) && !((i == Ar || i == Ar + 1) && (j == 1))) {
				diff_count++;
				diffCheck[i][j - 1] += (board[i][j] / 5);
			}

			//오른쪽으로 확산 가능한 경우
			if (j < C - 1) {
				diff_count++;
				diffCheck[i][j + 1] += (board[i][j] / 5);
			}

			//위쪽으로 확산 가능한 경우
			if ((i > 0) && !((i == Ar + 2) && (j == 0))) {
				diff_count++;
				diffCheck[i - 1][j] += (board[i][j] / 5);
			}

			//아래쪽으로 확산 가능한 경우
			if ((i < R - 1) && !((i == Ar - 1) && (j == 0))) {
				diff_count++;
				diffCheck[i + 1][j] += (board[i][j] / 5);
			}

			//(r, c)에 남은 미세먼지 계산
			diffCheck[i][j] -= ((board[i][j] / 5) * diff_count);
		}	
	}

	//확산된 미세먼지 변화 적용
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			board[i][j] += diffCheck[i][j];
	}
}

void air_cleaner() {
	int temp1, temp2;
	int x, y; //공기청정기 위치(순환 시작 위치)

	//위쪽 반시계방향 순환
	x = Ar, y = 1;
	temp1 = board[x][y];
	board[x][y] = 0;
	while (y < C - 1) {
		temp2 = board[x][y + 1];
		board[x][y + 1] = temp1;
		temp1 = temp2;
		y++;
	}
	while (x > 0) {
		temp2 = board[x - 1][y];
		board[x - 1][y] = temp1;
		temp1 = temp2;
		x--;
	}
	while (y > 0) {
		temp2 = board[x][y - 1];
		board[x][y - 1] = temp1;
		temp1 = temp2;
		y--;
	}
	while (x < Ar - 1) {
		temp2 = board[x + 1][y];
		board[x + 1][y] = temp1;
		temp1 = temp2;
		x++;
	}

	//아래쪽 시계방향 순환
	x = Ar + 1, y = 1;
	temp1 = board[x][y];
	board[x][y] = 0;
	while (y < C - 1) {
		temp2 = board[x][y + 1];
		board[x][y + 1] = temp1;
		temp1 = temp2;
		y++;
	}
	while (x < R - 1) {
		temp2 = board[x + 1][y];
		board[x + 1][y] = temp1;
		temp1 = temp2;
		x++;
	}
	while (y > 0) {
		temp2 = board[x][y - 1];
		board[x][y - 1] = temp1;
		temp1 = temp2;
		y--;
	}
	while (x > Ar + 2) {
		temp2 = board[x - 1][y];
		board[x - 1][y] = temp1;
		temp1 = temp2;
		x--;
	}
}

int main() {
	int T;
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		vector <int> t(C, 0);
		board.push_back(t);
	}
	diff_check = board;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < R; i++) {
		if (board[i][0] == -1) {
			Ar = i; //공기청정기 위치(행)
			break;
		}
	}

	for (int i = 0; i < T; i++) {
		diffuse();
		air_cleaner();
	}

	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			sum += board[i][j];
	}

	cout << sum + 2; // 공기청정기 두자리값(-2) 추가
	return 0;
}
