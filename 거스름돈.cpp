#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> money) {
	sort(money.begin(), money.end());
	vector <int> answer;
	answer.resize(n);

	for (int i = 0; i < n; i++) 
		if ((i + 1) % money[0] == 0) 
			answer[i] = 1; 

	for (int i = 1; i < money.size(); i++) {
		int current = money[i]; 
		for (int j = current - 1; j < n; j++) { 
			if (j == current - 1) 
				answer[j] = (answer[j] + 1) % 1000000007; 
			else if (j > current - 1) { 
				answer[j] = (answer[j] + answer[j - current]) % 1000000007;
			} 
		} 
	} 

	return answer[n - 1];
}
