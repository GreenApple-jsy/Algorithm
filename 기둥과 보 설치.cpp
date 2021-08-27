#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector <vector <int> > board(n + 1); //(-1)아무것도 없음, (0)기둥, (1)보, (2)둘 다 있음
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < n + 1; j++)
            board[i].push_back(-1);
    }

    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];  int y = build_frame[i][1];
        //기둥
        if (build_frame[i][2] == 0) {
            //설치
            if (build_frame[i][3] == 1) {
                //바닥 위에 있는 경우 가능
                if (y == 0) {
                    if (board[x][y] == -1)
                        board[x][y] = 0;
                    else if (board[x][y] == 1)
                        board[x][y] = 2;
                    continue;
                }

                //보의 오른쪽 끝 부분 위에 있는 경우 가능
                if (x > 0 && (board[x - 1][y] == 1 || board[x - 1][y] == 2)) {
                    if (board[x][y] == -1)
                        board[x][y] = 0;
                    else if (board[x][y] == 1)
                        board[x][y] = 2;
                    continue;
                }

                //보의 왼쪽 끝 부분 위에 있는 경우 가능
                if (board[x][y] == 1 || board[x][y] == 2) {
                    if (board[x][y] == -1)
                        board[x][y] = 0;
                    else if (board[x][y] == 1)
                        board[x][y] = 2;
                    continue;
                }

                //아래에 기둥이 있는 경우 가능
                if (y > 0 && (board[x][y - 1] == 0 || board[x][y - 1] == 2)) {
                    if (board[x][y] == -1)
                        board[x][y] = 0;
                    else if (board[x][y] == 1)
                        board[x][y] = 2;
                    continue;
                }
            }
            //삭제
            else if (build_frame[i][3] == 0) {
                //왼쪽 끝이 걸쳐진 보가 있고 보 오른쪽 아래에 기둥이 없고 양 옆으로 보가 하나라도 없는 경우 불가
                if (y < n) {  
                    if (board[x][y + 1] == 1 || board[x][y + 1] == 2) {
                        if (x < n && (board[x + 1][y] == -1 || board[x + 1][y] == 1)) {
                            if ((x > 0 && (board[x - 1][y + 1] == -1 || board[x - 1][y + 1] == 0)) ||
                                (board[x + 1][y + 1] == -1 || board[x + 1][y + 1] == 0))
                                continue;
                        }
                    }
                }

                //오른쪽 끝이 걸쳐진 보가 있고 보 왼쪽 아래에 기둥이 없고 양 옆으로 보가 하나라도 없는 경우 불가
                if (x > 0 && y < n) {
                    if (board[x - 1][y + 1] == 1 || board[x - 1][y + 1] == 2) {
                        if ((board[x - 1][y] == -1 || board[x - 1][y] == 1)) {
                            if ((x > 1 && (board[x - 2][y + 1] == -1 || board[x - 2][y + 1] == 0)) ||
                                (board[x][y + 1] == -1 || board[x][y + 1] == 0))
                                continue;
                        }
                    }
                }

                //위에 기둥이 있고, 그 기둥 밑 양 옆에 보가 아예 없는 경우 불가
                if (y < n && (board[x][y + 1] == 0 || board[x][y + 1] == 2)) {
                    if ((board[x][y + 1] == -1 || board[x][y + 1] == 0) &&
                        (x > 0 && (board[x - 1][y + 1] == -1 || board[x - 1][y + 1] == 0)))
                        continue;
                }
                
                //그 외의 경우 삭제 가능
                if (board[x][y] == 0)
                    board[x][y] = -1;
                else if (board[x][y] == 2)
                    board[x][y] = 1;
            }
        }
        //보
        else {
            //설치
            if (build_frame[i][3] == 1) {
                // 왼쪽 끝 부분이 기둥 위에 있는 경우 가능
                if (y > 0 && (board[x][y - 1] == 0 || board[x][y - 1] == 2)) {
                    if (board[x][y] == -1)
                        board[x][y] = 1;
                    else if (board[x][y] == 0)
                        board[x][y] = 2;
                    continue;
                }
                // 오른쪽 끝 부분이 기둥 위에 있는 경우 가능
                if (x < n && y > 0 && (board[x + 1][y - 1] == 0 || board[x + 1][y - 1] == 2)) {
                    if (board[x][y] == -1)
                        board[x][y] = 1;
                    else if (board[x][y] == 0)
                        board[x][y] = 2;
                    continue;
                }
                //양쪽 끝 부분이 다른 보와 동시에 연결되는 경우 가능
                if ((x < n && (board[x + 1][y] == 1 || board[x + 1][y] == 2)) &&
                    (x > 0 && (board[x - 1][y] == 1 || board[x - 1][y] == 2))) {
                    if (board[x][y] == -1)
                        board[x][y] = 1;
                    else if (board[x][y] == 0)
                        board[x][y] = 2;
                    continue;
                }
            }
            //삭제
            else if (build_frame[i][3] == 0) {
                //왼쪽 끝 위에 기둥이 있고 그 밑에 기둥이 없고 왼쪽 아래에 보가 없는 경우 불가
                if (board[x][y] == 0 || board[x][y] == 2) {
                    if ((y > 0 && (board[x][y - 1] == -1 || board[x][y - 1] == 1)) &&
                        (x > 0 && (board[x - 1][y] == -1 || board[x - 1][y] == 0)))
                        continue;
                }

                //오른쪽 끝 위에 기둥이 있고 그 밑에 기둥이 없고 오른쪽 아래에 보가 없는 경우 불가
                if (x < n  && (board[x + 1][y] == 0 || board[x + 1][y] == 2)) {
                    if ((y > 0 && (board[x + 1][y - 1] == -1 || board[x + 1][y - 1] == 1)) && 
                        (x < n && (board[x + 1][y] == -1 || board[x + 1][y] == 0)))
                        continue;
                }

                //양쪽 끝이 둘 다 기둥과 연결되어있지 않은 보가 왼쪽과 연결된 경우 불가
                if (x > 0 && (board[x - 1][y] == 1 || board[x - 1][y] == 2)) {
                    if (y > 0 && (board[x][y - 1] == -1 || board[x][y - 1] == 1) &&
                        (board[x - 1][y - 1] == -1 || board[x - 1][y - 1] == 1))
                        continue;
                }

                //양쪽 끝이 둘 다 기둥과 연결되어있지 않은 보가 오른쪽과 연결된 경우 불가
                if (x < n  && (board[x + 1][y] == 1 || board[x + 1][y] == 2)) {
                    if ((board[x + 1][y - 1] == -1 || board[x + 1][y - 1] == 1) && 
                        (x < n - 1 && (board[x + 2][y - 1] == -1 || board[x + 2][y - 1] == 1)))
                        continue;
                }

                //그 외의 경우 삭제 가능
                if (board[x][y] == 1)
                    board[x][y] = -1;
                else if (board[x][y] == 2)
                    board[x][y] = 0;
            }
        }
    }
    
    vector<vector<int>> answer;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0)
                answer.push_back({ i, j, 0 });  
            else if (board[i][j] == 1)
                answer.push_back({ i, j, 1 });
            else if (board[i][j] == 2) {
                answer.push_back({ i, j, 0 });
                answer.push_back({ i, j, 1 });
            }
        }
    }
    return answer;
}
