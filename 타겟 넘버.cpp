#include <string>
#include <vector>

using namespace std;
int answer;
int gtarget;

void dfs(int sum, int pos, vector<int> &numbers) {
	if (pos == numbers.size()) {
		if (sum == gtarget)
			answer++;
		return;
	}
	dfs(sum + numbers[pos], pos + 1, numbers);
	dfs(sum - numbers[pos], pos + 1, numbers);
	return;
}


int solution(vector<int> numbers, int target) {
	answer = 0;
	gtarget = target;
	dfs(0, 0, numbers);
	return answer;
}