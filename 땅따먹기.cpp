#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
	for (int i = 1; i < land.size(); i++) {     
		for (int j = 0; j < 4; j++)
			land[i][j] += previous_max(land[i - 1], j);
	}
	return *max_element((land.back()).begin(), (land.back()).end());
}

int main() {
	cout << solution({ {1,2,3,5},{5,6,7,8},{4,3,2,1} });
	system("pause");
}
