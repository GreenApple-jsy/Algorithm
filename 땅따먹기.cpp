#include <vector>
#include <algorithm>
using namespace std;

int previous_max(vector<int> &previous_line, int index) {
	if (index == 0)
		return *max_element(previous_line.begin() + 1, previous_line.end());
	else if (index == 1)
		return (previous_line[0] > *max_element(previous_line.begin() + 2, previous_line.end())) ? previous_line[0] : *max_element(previous_line.begin() + 2, previous_line.end());
	else if (index == 2)
		return (previous_line[3] > *max_element(previous_line.begin(), previous_line.begin() + 2)) ? previous_line[3] : *max_element(previous_line.begin(), previous_line.begin() + 2);
	else if (index == 3)
		return *max_element(previous_line.begin(), previous_line.end() - 1);
}

int solution(vector<vector<int> > land)
{
	for (int i = 1; i < land.size(); i++) {
		for (int j = 0; j < 4; j++)
			land[i][j] += previous_max(land[i - 1], j); //이전 행에서 같은 열을 제외한 원소들 중 가장 큰 원소를 더함
	}
	return *max_element((land.back()).begin(), (land.back()).end());
}
