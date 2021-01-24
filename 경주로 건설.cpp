#include <vector>
#include <queue>
using namespace std;

struct Car {
    int x, y;
    int current_direction; //0:왼쪽, 1:오른쪽, 2:위, 3:아래
    int cost; //누적 코스트
};

int solution(vector<vector<int>> board) {
    board[0][0] = -1;
    int N = board.size();
    int min_cost = 99999999;
    int mx[] = { 0, 0, -1, 1 }, my[] = { -1, 1, 0, 0 }; //왼쪽, 오른쪽, 위, 아래
    queue <Car> q;

    if (board[0][1] == 0) { //장애물 없을 경우 오른쪽 방향 스타트 추가
        q.push({ 0, 1, 1, 100 });
        board[0][1] = 100;
    }
    if (board[1][0] == 0) { //장애물 없을 경우 아래 방향 스타트 추가
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

            //범위 초과이거나 장애물이 있는 경우
            if ((new_x < 0) || (new_y < 0) || (new_x >= N) || (new_y >= N) || (board[new_x][new_y] == 1))
                continue;

            int new_cost = c.cost + 100;
            if (c.current_direction != i)
                new_cost += 500;

            // 장애물이 없고 방문한 적이 없거나, 새로 계산한 가격이 이전 기록한 값보다 작거나 같은 경우
            // queue에 추가 및 가격 갱신
            if ((board[new_x][new_y] == 0) || (new_cost <= board[new_x][new_y])) {
                Car d{ new_x, new_y, i, new_cost};
                q.push(d);
                board[new_x][new_y] = new_cost;
            }
        }
    }
    return min_cost;
}
