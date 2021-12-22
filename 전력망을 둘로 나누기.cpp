#include <string>
#include <vector>
using namespace std;

vector < vector<bool>> board;
int N;
int min_diff;

//연결된 송전탑 카운트
void DFS(int pos, int &cnt) {
    cnt++;
    for (int i = 1; i <= N; ++i) {
        if (board[pos][i] == true) {
            board[pos][i] = false;
            board[i][pos] = false;
            DFS(i, cnt);
            board[pos][i] = true;
            board[i][pos] = true;
        }  
    }
}

void getDiff(int a, int b) {
    int g1_cnt = 0, g2_cnt = 0;
    DFS(a, g1_cnt);
    DFS(b, g2_cnt);
    if (abs(g1_cnt - g2_cnt) < min_diff)
        min_diff = abs(g1_cnt - g2_cnt);
}

int solution(int n, vector<vector<int>> wires) {
    N = n;
    min_diff = n;
    board.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j)
            board[i].push_back(false);
    }

    for (int i = 0; i < wires.size(); ++i) {
        board[wires[i][0]][wires[i][1]] = true;
        board[wires[i][1]][wires[i][0]] = true;
    }

    //전선을 하나씩 끊어보며 송전탑 개수 차이 최소값 갱신
    for (int i = 0; i < wires.size(); ++i) {
        board[wires[i][0]][wires[i][1]] = false;
        board[wires[i][1]][wires[i][0]] = false;

        getDiff(wires[i][0], wires[i][1]);

        board[wires[i][0]][wires[i][1]] = true;
        board[wires[i][1]][wires[i][0]] = true;
    }

    return min_diff;
}
