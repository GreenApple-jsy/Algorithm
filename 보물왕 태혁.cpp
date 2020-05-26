#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	vector<int> divisors;
	string answer;
	int T, P;
	cin >> T;
	for (int i = 0; i < T; i++) {
		answer += "#" + to_string(i + 1) + " ";
		cin >> P;
		divisors.resize(P);
		for (int j = 0; j < P; j++)
			cin >> divisors[j];

		//1과 N을 제외한 약수 중, 가장 작은 약수와 가장 큰 약수를 곱한다
		answer += to_string(*max_element(divisors.begin(), divisors.end()) * *min_element(divisors.begin(), divisors.end())) + "\n";
	}
	cout << answer;
	return 0;
}
