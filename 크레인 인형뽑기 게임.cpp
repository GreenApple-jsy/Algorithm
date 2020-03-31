#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<vector<int>> myBoard;
    vector<int> basket;
    vector<int> temp;
    int answer = 0;
    int N = board.size();
    for (int k = 0; k < N; k++) {
        myBoard.push_back(temp);
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) {
                myBoard[j].push_back(board[i][j]);
            }
        }
    }

    for (int i = 0; i < moves.size(); i++) {
        if (myBoard[moves[i] - 1].size() > 0) { //해당 라인에 인형이 남아있다면
            basket.push_back(myBoard[moves[i] - 1].back()); //바구니에 넣기
            myBoard[moves[i] - 1].erase(myBoard[moves[i] - 1].end() - 1); //라인에서 맨 위의 인형 빼기

            if (basket.size() >= 2) {
                if (basket[basket.size() - 1] == basket[basket.size() - 2]) {
                    basket.erase(basket.end() - 2, basket.end()); //종류가 같은 인형 지우기
                    answer += 2;
                }
            }
        }
    }
    return answer;
}
