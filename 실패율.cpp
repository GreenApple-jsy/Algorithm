#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector <vector<double>> failure(N, vector<double>(2)); //������,������ȣ ����
	int people = stages.size(); //����� ��
	int current_index = 0; 
	sort(stages.begin(), stages.end());
	for (int i = 1; i <= N; i++) {
		int count = 0;
		int understage = current_index; //�ش� ���������� ���� ���� ��� ��
		while ((current_index < stages.size()) && (stages[current_index] <= i)) {
			if (stages[current_index] == i) //���� �ش� ���������� �����
				count++;
			current_index++;
		}
		if (people - understage == 0) //���������� ������ ����ڰ� ���� ��� �������� 0���� ó��
			failure[i - 1][0] = 0;
		else
			failure[i - 1][0] = (double)count / (people - understage); //������ = ���� �ش� ���������� ����� / (��ü ����� �� - �ش� ���������� ���� ���� ��� ��)
		failure[i - 1][1] = i;
	}
	sort(failure.begin(), failure.end());
	for (int i = failure.size() - 1; i >= 0; i--) { //�������� ������������ ����
		if ((i != 0) && (failure[i][0] == failure[i - 1][0])) { //���� �������϶� ���� �������� ����
			int temp = i;
			while ((temp != 0) && (failure[temp][0] == failure[temp - 1][0]))
				temp--;
			for (int j = temp; j <= i; j++)
				answer.push_back(failure[j][1]);
			i = temp;
		}
		else 
			answer.push_back(failure[i][1]);
	}
	return answer;
}