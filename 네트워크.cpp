#include <string>
#include <vector>
using namespace std;

bool Connected[200]; //����� ��ǻ�ʹ� true���� ����

void Check(int n, int i, vector<vector<int>> &computers) {
	Connected[i] = true;
	for (int j = 0; j < n; j++) {
		if ((computers[i][j] == 1) && (i != j)) {
			computers[i][j] = 0; //������ Ȯ���� ��ǻ�ʹ� �迭 ���� 0���� �ٲ�
			Check(n, j, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int Network = 0;
	int NotConnected = 0;
	for (int t = 0; t < n; t++) //�迭 �ʱ�ȭ
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
	for (int k = 0; k < n; k++) { //������� ���� ��ǻ�� ���� Ȯ��
		if (Connected[k] == false)
			NotConnected++;
	}
	return Network + NotConnected;
}