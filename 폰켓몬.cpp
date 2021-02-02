#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
	int answer = nums.size() / 2;
	unordered_set <int> set(nums.begin(), nums.end());
	if (answer > set.size())
		answer = set.size();
	return answer;
}
