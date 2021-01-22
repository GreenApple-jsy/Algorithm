#include <string>
#include <vector>
#include <iostream>
using namespace std;

int min_coast;
vector<vector<int>> g_board;
int board_size;

// 0 : 오른쪽, 1 : 아래, 2 : 왼쪽, 3 : 위
void find_route(int x, int y, int direction, int current_cost, vector<vector<bool>> board_visit_check) {
    cout << x << " , " << y <<  "   //" << current_cost << endl;
    if ((x == g_board.size() - 1) && (y == g_board.size() - 1)) {
        if (current_cost < min_coast)
            min_coast = current_cost;
        return;
    }
    //오른쪽
    if ((y + 1 < board_size) && (board_visit_check[x][y + 1] == false) && (g_board[x][y + 1] == 0)) {
        int temp_coast = current_cost;
        if (direction != 0)
            temp_coast += 500;
        temp_coast += 100;
        board_visit_check[x][y + 1] = true;
        find_route(x, y + 1, 0, temp_coast, board_visit_check);
        board_visit_check[x][y + 1] = false;
    }
    //아래
    if ((x + 1 < board_size) && (board_visit_check[x + 1][y] == false) && (g_board[x + 1][y] == 0)) {
        int temp_coast = current_cost;
        if (direction != 1)
            temp_coast += 500;
        temp_coast += 100;
        board_visit_check[x + 1][y] = true;
        find_route(x + 1, y, 1, temp_coast, board_visit_check);
        board_visit_check[x + 1][y] = false;
    }

    //왼쪽
    if ((y - 1 >= 0) && (board_visit_check[x][y - 1] == false) && (g_board[x][y - 1] == 0)) {
        int temp_coast = current_cost;
        if (direction != 2)
            temp_coast += 500;
        temp_coast += 100;
        board_visit_check[x][y - 1] = true;
        find_route(x, y - 1, 2, temp_coast, board_visit_check);
        board_visit_check[x][y - 1] = false;
    }

    //위
    if ((x - 1 >= 0) && (board_visit_check[x - 1][y] == false) && (g_board[x - 1][y] == 0)) {
        int temp_coast = current_cost;
        if (direction != 3)
            temp_coast += 500;
        temp_coast += 100;
        board_visit_check[x - 1][y] = true;
        find_route(x - 1, y, 3, temp_coast, board_visit_check);
        board_visit_check[x - 1][y] = false;
    }
    return;
}



int solution(vector<vector<int>> board) {
    min_coast = 99999999;
    g_board = board;
    board_size = board.size();
    vector <bool> temp(board_size, false);
    vector<vector<bool>> board_visit_check;
    for (int i = 0; i < board_size; i++)
        board_visit_check.push_back(temp);

    if (board[0][1] == 0) {
        board_visit_check[0][1] = true;
        find_route(0, 1, 0, 100, board_visit_check);
        board_visit_check[0][1] = false;
    }
        
    if (board[1][0] == 0) {
        board_visit_check[1][0] = true;
        find_route(1, 0, 1, 100, board_visit_check);
        board_visit_check[1][0] = false;
    }
    return min_coast;
}
