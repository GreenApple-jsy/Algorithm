#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	int nTops = heights.size(); //탑 개수

	for (int i = 0; i < nTops; i++) {
		answer.push_back(0); //0으로 초기화
	}

	for (int i = nTops - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (heights[j] > heights[i]) {
				answer[i] = j + 1;
				break;
			}
		}
	}
	return answer;
}