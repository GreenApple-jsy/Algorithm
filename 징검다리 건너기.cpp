#include <string>
#include <vector>
using namespace std;

bool check(int num, vector<int>& stones, int k) {
	int N = 0;
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] - num <= 0)
			N++;
		else
			N = 0;

		if (N >= k)
			return false;
	}
	return true;
}

int solution(vector<int> stones, int k) {
	int left = 1;
	int right = 200000001;
	int mid = (left + right) / 2;
	while (left <= right) { //이분탐색으로 가능한 최대 친구 수 찾기
		if (check(mid, stones, k))
			left = mid + 1;
		else
			right = mid - 1;

		mid = (left + right) / 2;
	}
	return left;
}