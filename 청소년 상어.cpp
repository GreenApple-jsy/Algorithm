#include <iostream>
using namespace std;

int max_sum;

struct shark {
	pair<int, int> pos = { 0,0 };
	int dir;
	int fish_count;
};

int main() {
	pair<int, int> board[4][4];
	int a, b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			board[i][j] = make_pair(a, b);
		}
	}
	shark s{ { 0,0 }, board[0][0].second, board[0][0].first };

	board[0][0] = { -1,-1 }; //상어가 있는 칸

	max_sum = board[0][0].first;
	
	cout << max_sum;
	return 0;
}
