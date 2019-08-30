#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
	long sum{ 0 };
	int temp, answer;
	int size = budgets.size();
	int start, back;

	sort(budgets.begin(), budgets.end()); //값 크키순으로 정렬
	start = budgets.front();
	back = budgets.back();

	for (int i = 0; i < size; i++)
		sum += budgets[i];
	if (sum <= M) //모든 조건 금액을 만족시킬 경우 바로 제일 큰 값 리턴
		return budgets.back();

	answer = M / size; //answer 기본 값은 예산 / 지방의 수

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
				answer = temp; //최대값 업데이트

			start = ((start + back) / 2) + 1;
		}
		else if (sum > M)
			back = ((start + back) / 2) - 1;

		if (start > back)
			break;
	}
	return answer;
}