#include <iostream>
#include <vector>
using namespace std;

int max_sum;

//DFS로 풀이
void find_max(vector <pair <int, int>>& TP, int currentN, int sum) {
	if (sum > max_sum)
		max_sum = sum;
	for (int i = currentN; i < TP.size(); i++) {
		if (i + TP[i].first <= TP.size())
			find_max(TP, i + TP[i].first, sum + TP[i].second);
	}
	return;
}

int main() {
	max_sum = 0;
	int N;
	cin >> N;
	vector <pair <int, int>> TP(N);
	for (int i = 0; i < N; i++)
		cin >> TP[i].first >> TP[i].second;
	find_max(TP, 0, 0);
	cout << max_sum;
	return 0;
}
