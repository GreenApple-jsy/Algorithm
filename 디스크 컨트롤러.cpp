#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1]; //짧은 작업 시간 우선
	}
};

int solution(vector<vector<int>> jobs) {
	sort(jobs.begin(), jobs.end());
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	vector <int> temp;
	int current_time = 0;
	int time_sum = 0;
	int index = 0;
	int jobsLeft = jobs.size();
	while (jobsLeft > 0) {
		while ((index < jobs.size()) && (jobs[index][0] <= current_time)) {
			pq.push(jobs[index]); //현 시점에서 시작 가능한 작업들만 우선순위 큐에 삽입
			index++;
		}
		if (!pq.empty()) {
			temp = pq.top();
			if (temp[0] <= current_time) {
				time_sum += (current_time - temp[0]) + temp[1];
				pq.pop();
				jobsLeft--;
				current_time += temp[1];
			}
			else {
				current_time = temp[0];
			}
		}
		else { //시작 가능한 작업이 없을 경우, 시간 증가
			current_time++;
		}
	}
	return (time_sum / jobs.size());
}