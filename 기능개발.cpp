#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue <int> pr;
	queue <int> sp;
	int day = 1;
	for (int i = 0; i < progresses.size(); i++) {
		pr.push(progresses[i]);
		sp.push(speeds[i]);
	}
	while (!pr.empty()) {
		int finished = 0;
		int s = pr.size();
		for (int j = 0; j < s; j++) {
			if ((pr.front() +( sp.front() * day)) >= 100) {
				finished++;
				pr.pop();
				sp.pop();
			}
		}
		if (finished != 0)
			answer.push_back(finished);
		day++;
	}
	return answer;
}