#include <vector>
#include <queue>
using namespace std;

struct Car {
    int x, y;
    int current_direction; //0:왼쪽, 1:오른쪽, 2:위, 3:아래
    int cost;
};

int solution(vector<vector<int>> board) {
    board[0][0] = -1;
    int N = board.size();
    int min_cost = 99999999;
    int mx[] = { 0, 0, -1, 1 }, my[] = { -1, 1, 0, 0 };
    queue <Car> q;
    if (board[0][1] == 0) {
        q.push({ 0, 1, 1, 100 });
        board[0][1] = 100;
    }
    if (board[1][0] == 0) {
        q.push({ 1, 0, 3, 100 });
        board[1][0] = 100;
    }   
    while (!q.empty()) {
        Car c = q.front();
        q.pop();
        if ((c.x == N - 1) && (c.y == N - 1)) {
            if (c.cost < min_cost)
                min_cost = c.cost;
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int new_x = c.x + mx[i];
            int new_y = c.y + my[i];

            if ((new_x < 0) || (new_y < 0) || (new_x >= N) || (new_y >= N) || (board[new_x][new_y] == 1))
                continue;

            int new_cost = c.cost + 100;
            if (c.current_direction != i)
                new_cost += 500;

            if ((board[new_x][new_y] == 0) || (new_cost <= board[new_x][new_y])) {
                Car d{ new_x, new_y, i, new_cost};
                q.push(d);
                board[new_x][new_y] = new_cost;
            }
        }
    }
    return min_cost;
}
