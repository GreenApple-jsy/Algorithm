#include <string>
#include <vector>
using namespace std;

int answer;
int boardSize;

bool check(int h, int w, vector<vector<bool>> &chessBoard) { //퀸 배치가 가능한 위치인지 체크
	for (int i = 0; i < h; i++) { //세로 체크
		if (chessBoard[i][w] == true)
			return false;
	}
	int h1 = h - 1; int w1 = w - 1;
	while (h1 >= 0 && w1 >= 0) { //왼쪽 위 대각선 체크
		if (chessBoard[h1][w1] == true)
			return false;
		h1--; w1--;
	}
	while (h >= 0 && w <= boardSize) { //오른쪽 위 대각선 체크
		if (chessBoard[h][w] == true)
			return false;
		h--; w++;
	}
	return true;
}

void dfs(int currentN, vector<vector<bool>> chessBoard) {
	if (currentN == boardSize + 1) {
		answer++;
		return;
	}
	for (int i = 0; i <= boardSize; i++) {
		if (check(currentN, i, chessBoard)) {
			chessBoard[currentN][i] = true;
			dfs(currentN + 1, chessBoard);
			chessBoard[currentN][i] = false;
		}
	}
	return;
}

int solution(int n) {
	answer = 0;
	boardSize = n - 1;
	vector<vector<bool>> chessBoard(n, vector<bool>(n, false));
	dfs(0, chessBoard);
	return answer;
}