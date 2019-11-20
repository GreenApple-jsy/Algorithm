#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> temp;

void getSum(int sum, int pos, int c, vector<int> &nums) { 
	if (c == 3) {
		if (find(temp.begin(), temp.end(), sum) == temp.end()) //중복이 아닌 합만 저장
			temp.push_back(sum);
		return;
	}
	for (int i = pos; i < nums.size(); i++)
		getSum(sum + nums[i], i + 1, c + 1, nums);
	return;
}

int main() {
	string answer = "";
	int N;
	cin >> N;
	vector <int> nums(7);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 7; j++)
			cin >> nums[j];
		getSum(0, 0, 0, nums); //3개의 수의 전체 조합 구하기
		sort(temp.begin(), temp.end());
		answer += "#" + to_string(i) + " " + to_string(temp[temp.size() - 5]) + "\n";
		temp.clear();
	}
	cout << answer;
}