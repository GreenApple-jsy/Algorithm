#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int temp;
	int s = prices.size();
	for (int i = 0; i < s; i++) {
		temp = 0;
		for (int j = i + 1; j < s; j++, temp++) {
			if (prices[i] > prices[j]) {
				temp++;
				break;
			}
		}
		answer.push_back(temp);
	}
	return answer;
}
