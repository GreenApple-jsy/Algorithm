#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int solution(int n, vector<int> v) {
	int count{ 0 };
	int LeftSum{ 0 };
	int RightSum{ 0 };

	for (int i = 0; i < n; i++)
		RightSum = RightSum + v[i];

	int MinDiff = abs(RightSum);

	for (int j = 0; j < n; j++) {
		LeftSum = LeftSum + v[j];
		RightSum = RightSum - v[j];
		if (abs(LeftSum - RightSum) < MinDiff) {
			MinDiff = abs(LeftSum - RightSum);
			count = j + 1;
		}
	}
	return count;
}