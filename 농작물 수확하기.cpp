#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector <vector <int>> farm;
	string answer;
	int T, N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		farm.resize(N);
		for (int j = 0; j < N; j++) {
			farm[j].resize(N);
			
		}
	}
	cout << answer;
	return 0;
}
