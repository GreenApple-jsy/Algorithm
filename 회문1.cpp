#include <iostream>
using namespace std;

int main() {
	for (int tc = 1; tc <= 10; ++tc) {
		char board[8][8];
		int size, count = 0;
		cin >> size;
		bool isEven = size % 2 == 0;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j)
				cin >> board[i][j];
		}

		string a, b;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				//세로 탐색
				if (i <= 8 - size) {
					a = "", b = "";
					for (int k = i; k < i + size / 2; ++k)
						a += board[k][j];
					//회문 길이가 짝수인 경우
					if (isEven) {
						for (int k = i + size - 1; k >= i + size / 2; --k)
							b += board[k][j];
					}
					//회문 길이가 홀수인 경우
					else {
						for (int k = i + size - 1; k > i + size / 2; --k)
							b += board[k][j];
					}
					if (a == b)
						count++;
				}
				//가로 탐색
				if (j <= 8 - size) {
					a = "", b = "";
					for (int k = j; k < j + size / 2; ++k)
						a += board[i][k];
					//회문 길이가 짝수인 경우
					if (isEven) {
						for (int k = j + size - 1; k >= j + size / 2; --k)
							b += board[i][k];
					}
					//회문 길이가 홀수인 경우
					else {
						for (int k = j + size - 1; k > j + size / 2; --k)
							b += board[i][k];
					}
					if (a == b)
						count++;
				}
			}
		}
		cout << "#" << tc << " " << count << endl;
	}
	return 0;
}
