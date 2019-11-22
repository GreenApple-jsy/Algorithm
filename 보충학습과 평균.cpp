#include <iostream>
#include <string>
using namespace std;

int main() {
	string answer;
	int N;
	int score_sum, temp;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		score_sum = 0;
		for (int j = 0; j < 5; j++) {
			cin >> temp;
			if (temp < 40)
				temp = 40;
			score_sum += temp;
		}
		answer += "#" + to_string(i) + " " + to_string(score_sum / 5) + "\n";
	}
	cout << answer;
	return 0;
}