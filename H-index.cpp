#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int size = citations.size();
	sort(citations.begin(),citations.end());
	for (int i = size; i > 0; i--) {
		if (citations[size - i] >= i)
			return i;
	}
	return 0;
}