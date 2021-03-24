#include <vector>
using namespace std;

vector<vector<int>> g_arr;
int zero_count, one_count;

//x = 가로 , y = 세로
//쿼드의 왼쪽 위 꼭지점 좌표, 오른쪽 아래 꼭지점 좌표
void CompressQuad(int x1, int y1, int x2, int y2) {
    int previous_val = g_arr[y1][x1];
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {

            //쿼드 내의 모든 수가 같지 않다면 4개의 쿼드로 쪼갬
            if (g_arr[i][j] != previous_val) { 
                CompressQuad(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
                CompressQuad((x1 + x2) / 2, y1, x2, (y1 + y2) / 2);
                CompressQuad(x1, (y1 + y2) / 2, (x1 + x2) / 2, y2);
                CompressQuad((x1 + x2) / 2, (y1 + y2) / 2, x2, y2);
                return;
            }
            previous_val = g_arr[i][j];
        }
    }

    //쿼드 내의 모든 수가 같다면 0 또는 1을 카운트 해줌
    if (g_arr[y1][x1] == 0)
        zero_count++;
    else
        one_count++;
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    zero_count = 0; one_count = 0;
    g_arr = arr;
    CompressQuad(0, 0, arr.size(), arr.size());
    return { zero_count, one_count };
}
