#include <string>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
	vector <int> locations;
	int answer = 1;
	int j = 1;
	for (int i = 0; i < priorities.size(); i++)
		locations.push_back(i);
	while (priorities.size() > 1) {
		for (j = 1; j < priorities.size(); j++) {
			if (priorities.front() < priorities[j])
				break;
		}
		if (j == priorities.size()) {
			if (locations.front() == location)
				return answer;
			answer++;
		}
		else {
			priorities.push_back(priorities.front());
			locations.push_back(locations.front());
		}
		priorities.erase(priorities.begin());
		locations.erase(locations.begin());
	}
	return answer;
}