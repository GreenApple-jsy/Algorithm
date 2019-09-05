#include <string>
#include <vector>
using namespace std;

bool Connected[200]; //연결된 컴퓨터는 true값을 가짐

void Check(int n, int i, vector<vector<int>> &computers) {
	Connected[i] = true;
	for (int j = 0; j < n; j++) {
		if ((computers[i][j] == 1) && (i != j)) {
			computers[i][j] = 0; //연결을 확인한 컴퓨터는 배열 값을 0으로 바꿈
			Check(n, j, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int Network = 0;
	int NotConnected = 0;
	for (int t = 0; t < n; t++) //배열 초기화
		Connected[t] = false;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (computers[i][j] == 1) {
				computers[i][j] = 0;
				Connected[i] = true;
				Network++;
				Check(n,j,computers);
			}
		}
	}
	for (int k = 0; k < n; k++) { //연결되지 않은 컴퓨터 개수 확인
		if (Connected[k] == false)
			NotConnected++;
	}
	return Network + NotConnected;
}