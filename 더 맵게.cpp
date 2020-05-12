#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int m, n;
	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0; i < scoville.size(); i++)
		pq.push(scoville[i]);

	while ((pq.top() < K) && (pq.size() > 1)) {
		//가장 덜 매운 두 음식을 빼서 합치기
		m = pq.top();
		pq.pop();
		n = pq.top();
		pq.pop();
		pq.push(m + (2 * n));
		answer++;
	}

	if (pq.top() < K)
		return -1;

	return answer;
}
