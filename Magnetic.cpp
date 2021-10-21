#include <iostream>
using namespace std;

int main() {
    for (int tc = 1; tc <= 10; ++tc) {
        int N, count = 0;
        cin >> N;
        int board[101][101] = {{0,},};

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cin >> board[i][j];
        }
        for (int i = 0; i < N; i++) {
            bool check = 0;

            for (int j = 0; j < N; j++) {
                if (check == 0 && board[j][i] == 2)
                    continue;
                else if (board[j][i] == 0)
                    continue;
                else if (board[j][i] == 1)
                    check = 1;
                else if (check == 1 && board[j][i] == 2) {
                    count++;
                    check = false;
                }
            }
        }
        cout << "#" << tc << " " << count << endl;
    }
    return 0;
}
