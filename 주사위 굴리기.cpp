#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> dice_sides = { 0, 0, 0, 0, 0, 0}; //주사위 각 면의 숫자
	int N, M, x, y, K, input;
	cin >> N >> M >> x >> y >> K;
	vector <vector <int>> board(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			board[i].push_back(input);
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> input;
		if (input == 1) { //동
			if (y < M - 1) {
				y++;
				int temp = dice_sides[0];
				dice_sides[0] = dice_sides[3];
				dice_sides[3] = dice_sides[5];
				dice_sides[5] = dice_sides[2];
				dice_sides[2] = temp;
				if (board[x][y] == 0) { //이동한 칸에 쓰여 있는 수가 0인 경우
					board[x][y] = dice_sides[5];
				}
				else {
					dice_sides[5] = board[x][y];
					board[x][y] = 0;
				}
				cout << dice_sides.front() << endl; //주사위 윗 면의 수 출력
			}
		}
		else if (input == 2) { //서
			if (y > 0) {
				y--;
				int temp = dice_sides[0];
				dice_sides[0] = dice_sides[2];
				dice_sides[2] = dice_sides[5];
				dice_sides[5] = dice_sides[3];
				dice_sides[3] = temp;
				if (board[x][y] == 0) { //이동한 칸에 쓰여 있는 수가 0인 경우
					board[x][y] = dice_sides[5];
				}
				else {
					dice_sides[5] = board[x][y];
					board[x][y] = 0;
				}
				cout << dice_sides.front() << endl; //주사위 윗 면의 수 출력
			}
		}
		else if (input == 3) { //북
			if (x > 0) {
				x--;
				int temp = dice_sides[0];
				dice_sides[0] = dice_sides[4];
				dice_sides[4] = dice_sides[5];
				dice_sides[5] = dice_sides[1];
				dice_sides[1] = temp;
				if (board[x][y] == 0) { //이동한 칸에 쓰여 있는 수가 0인 경우
					board[x][y] = dice_sides[5];
				}
				else {
					dice_sides[5] = board[x][y];
					board[x][y] = 0;
				}
				cout << dice_sides.front() << endl; //주사위 윗 면의 수 출력
			}
		}
		else if (input == 4) { //남
			if (x < N - 1) {
				x++;
				int temp = dice_sides[0];
				dice_sides[0] = dice_sides[1];
				dice_sides[1] = dice_sides[5];
				dice_sides[5] = dice_sides[4];
				dice_sides[4] = temp;
				if (board[x][y] == 0) { //이동한 칸에 쓰여 있는 수가 0인 경우
					board[x][y] = dice_sides[5];
				}
				else {
					dice_sides[5] = board[x][y];
					board[x][y] = 0;
				}
				cout << dice_sides.front() << endl; //주사위 윗 면의 수 출력
			}
		}
	}
	return 0;
}
