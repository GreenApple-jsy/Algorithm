#include <string>
#include <vector>
#include <map>
using namespace std;

vector <vector <char>> b; //주어진 보드 블록 정보를 열단위로 저장
vector<vector <bool>> c; //제거할 블록 기록

int check(int x, int y) { //왼쪽 아래를 중심으로 2x2 사각형을 이루는지 체크
	char character = b[x][y];
	if (b[x + 1].size() <= y + 1) //오른쪽 위에 블록이 존재하는지 확인
		return 0;

	if ((b[x][y + 1] == character) && (b[x + 1][y] == character) && (b[x + 1][y + 1] == character)) { //4개의 블록이 같은 캐릭터라면
		int sum = 0;
		if (!c[x][y]) {
			sum++;
			c[x][y] = true;
		}
		if (!c[x + 1][y]) {
			sum++;
			c[x + 1][y] = true;
		}
		if (!c[x][y + 1]) {
			sum++;
			c[x][y + 1] = true;
		}
		if (!c[x + 1][y + 1]) {
			sum++;
			c[x + 1][y + 1] = true;
		}
		return sum;
	}
	else
		return 0;
}


int solution(int m, int n, vector<string> board) {
	int sum = 0;
	b.resize(n);
	c.resize(n);
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			b[j].push_back(board[i][j]);
			c[j].push_back(false);
		}
	}
	int popN;
	do {
		popN = 0;
		for (int i = 0; i <= (int)b.size() - 2; i++) {
			for (int j = 0; j <= (int)b[i].size() - 2; j++)
				popN += check(i, j);
		}
		sum += popN;
		for (int k = 0; k < c.size(); k++) { //위 -> 아래 방향으로 블록을 지움
			for (int p = c[k].size() - 1; p >= 0; p--) {
				if (c[k][p]) {
					c[k][p] = false;
					b[k].erase(b[k].begin() + p);
				}
			}
		}
	} while (popN != 0); //더 이상 제거되는 블록이 없을때까지
	return sum;
}