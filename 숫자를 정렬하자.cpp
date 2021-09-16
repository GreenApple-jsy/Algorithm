#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> num;
	int T, N;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> N;
		num.clear();
		num.resize(N);
		for (int j = 0; j < N; ++j)
			cin >> num[j];
		sort(num.begin(), num.end());
		cout << "#" << i;
		for (int j = 0; j < N; ++j)
			cout << " " << num[j];
		cout << "\n";
	}
	return 0;
}
