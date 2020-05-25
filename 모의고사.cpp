#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector <int> count = { 0,0,0 };
	vector <vector <int>> answer_list = { { 5,1,2,3,4 } , { 5,2,1,2,3,2,4,2 } , { 5,3,3,1,1,2,2,4,4,5 } };

	for (int i = 0; i < answers.size(); i++) {
		for (int j = 0; j < 3; j++) {
			if (answers[i] == answer_list[j][(i + 1) % answer_list[j].size()])
				count[j]++;
		}
	}

	int max = *max_element(count.begin(), count.end());

	for (int i = 0; i < 3; i++)
		if (max == count[i])
			answer.push_back(i + 1);

	return answer;
}
