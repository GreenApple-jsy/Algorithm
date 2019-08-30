#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
	long sum{ 0 };
	int temp, answer;
	int size = budgets.size();
	int start, back;

	sort(budgets.begin(), budgets.end()); //�� ũŰ������ ����
	start = budgets.front();
	back = budgets.back();

	for (int i = 0; i < size; i++)
		sum += budgets[i];
	if (sum <= M) //��� ���� �ݾ��� ������ų ��� �ٷ� ���� ū �� ����
		return budgets.back();

	answer = M / size; //answer �⺻ ���� ���� / ������ ��

	while (true) {
		temp = (start + back) / 2;
		sum = 0;

		for (int i = 0; i < size; i++) {
			if (budgets[i] <= temp)
				sum += budgets[i];
			else
				sum += temp;
		}
		if (sum <= M) {
			if (temp >= answer)
				answer = temp; //�ִ밪 ������Ʈ

			start = ((start + back) / 2) + 1;
		}
		else if (sum > M)
			back = ((start + back) / 2) - 1;

		if (start > back)
			break;
	}
	return answer;
}