#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	int nTops = heights.size(); //ž ����

	for (int i = 0; i < nTops; i++) {
		answer.push_back(0); //0���� �ʱ�ȭ
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