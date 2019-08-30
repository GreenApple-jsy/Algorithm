#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int size = triangle.size();
	vector<vector<int>> temp(size, vector<int>(size)); //더한 값 저장할 벡터

	temp[0][0] = triangle[0][0];
	for (int i = 1; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) //왼쪽 사이드
				temp[i][0] = temp[i - 1][0] + triangle[i][0];
			else if (j == i) //오른쪽 사이드
				temp[i][j] = temp[i - 1][j - 1] + triangle[i][j];
			else { //그 외
				temp[i][j] = max(temp[i - 1][j - 1] + triangle[i][j], temp[i - 1][j] + triangle[i][j]);
			}

			if (i == size - 1) //마지막 레벨
				answer = max(temp[i][j], answer);
		}
	}
	return answer;
}