#include <string>
#include <vector>
#include <map>
using namespace std;

vector <vector <char>> b; //�־��� ���� ��� ������ �������� ����
vector<vector <bool>> c; //������ ��� ���

int check(int x, int y) { //���� �Ʒ��� �߽����� 2x2 �簢���� �̷���� üũ
	char character = b[x][y];
	if (b[x + 1].size() <= y + 1) //������ ���� ����� �����ϴ��� Ȯ��
		return 0;

	if ((b[x][y + 1] == character) && (b[x + 1][y] == character) && (b[x + 1][y + 1] == character)) { //4���� ����� ���� ĳ���Ͷ��
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
		for (int k = 0; k < c.size(); k++) { //�� -> �Ʒ� �������� ����� ����
			for (int p = c[k].size() - 1; p >= 0; p--) {
				if (c[k][p]) {
					c[k][p] = false;
					b[k].erase(b[k].begin() + p);
				}
			}
		}
	} while (popN != 0); //�� �̻� ���ŵǴ� ����� ����������
	return sum;
}