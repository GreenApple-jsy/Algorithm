#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer;

bool dfs(int pos, vector<vector<string>> tickets) {
	bool result = false;
	string current = tickets[pos][1];
	answer.push_back(current);
	tickets.erase(tickets.begin() + pos);
	if (tickets.size() == 0)
		return true;
	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == current)
			result = dfs(i, tickets);
		if (result)
			return true;
	}
	answer.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	bool result = false;
	sort(tickets.begin(), tickets.end());
	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == "ICN") {
			answer.clear();
			answer.push_back("ICN");
			result = dfs(i, tickets);
			if (result)
				return answer;		
		}
	}
}