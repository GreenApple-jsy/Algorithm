#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int N, B, C;
	cin >> N;
	vector <int> tester(N);
	for (int i = 0; i < N; i++)
		cin >> tester[i];
	cin >> B >> C; //총감독관, 부감독관

	long long answer = 0;
	for (int i = 0; i < N; i++) {
		answer++;
		int leftN = tester[i] - B;
		if (leftN > 0)
			answer += ceil((double)leftN / C);
	}

	cout << answer;
	return 0;
}
