#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector <vector <int> > board(n); //(-1)아무것도 없음, (0)기둥, (1)보, (2)둘 다 있음
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < n; j++) {
            board[i].push_back(-1);
        }
    }

    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0], int y = build_frame[i][1];

        //기둥
        //기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다
        if (build_frame[i][2] == 0) {
            //삭제
            if (build_frame[i][3] == 0) {
                //보가 걸쳐져 있는 경우 불가
                if (board[x][y] == 1 || board[x][y] == 2)
                    continue;
                //위에 기둥이 있는 경우 불가
            }
            //설치
            else {
                //바닥 위에 있는 경우 가능

                //보의 한쪽 끝 부분 위에 있는 경우 가능

                //아래에 기둥이 있는 경우 가능
            }
        }
        //보
        //보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다
        else {
            //삭제
            if (build_frame[i][3] == 0) {
                //한쪽 끝 위에 기둥이 있는 경우 불가

                //한쪽 끝에 양쪽 끝이 보와 연결되어있는 보가 있는 경우 불가
            }
            //설치
            else {
                // 한쪽 끝 부분이 기둥 위에 있는 경우 가능

                //양쪽 끝 부분이 다른 보와 동시에 연결되는 경우 가능
            }
        }
    }
    
    
    
    
    vector<vector<int>> answer;




    return answer;
}
