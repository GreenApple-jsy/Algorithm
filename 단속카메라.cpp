#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int cameraN = 1;
	sort(routes.begin(), routes.end());
	int cposition = routes[0][1];
	for (int i = 1; i < routes.size(); i++) {
		if (routes[i][1] < cposition)
			cposition = routes[i][1];
		if (routes[i][0] > cposition) {
			cameraN++;
			cposition = routes[i][1];
		}
	}
	return cameraN;
}