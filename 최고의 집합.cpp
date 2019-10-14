#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;
	if (n > s) //������ ���� �� ���� ���
		answer.push_back(-1);
	else {
		int div = s / n;
		int diff = s % n;
		int pos = n - 1;
		answer.assign(n, div); //  ���� ���Ұ����� ���� ������ ������ ���� ä��
		for (int i = diff; i > 0; i--)  //�������� ���� ������ ������ ���Һ��� ���������� 1�� ������
			answer[pos--]++;
	}
	return answer;
}