#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g_board;
int max_size;

void check_near_board(int i, int j) {
	int min_num = g_board[i - 1][j - 1];

	if (g_board[i - 1][j] < min_num)
		min_num = g_board[i - 1][j];

	if (g_board[i][j - 1] < min_num)
		min_num = g_board[i][j - 1];

	g_board[i][j] *= (min_num + 1);

	if (max_size < g_board[i][j])
		max_size = g_board[i][j];
}

int solution(vector<vector<int>> board)
{
	max_size = 0;
	g_board = board;

	if (board.size() <= 1) {
		for (int i = 0; i < board[0].size(); i++) {
			if (board[0][i] == 1)
				return 1;
		}
		return 0;
	}

	for (int i = 1; i < board.size(); i++) {
		for (int j = 1; j < board[i].size(); j++) {
			check_near_board(i, j);
		}
	}
	
	return  max_size * max_size;
}
