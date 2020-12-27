#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string A, string B) {
	if (A.length() < B.length())
		return true;
	else if (A.length() == B.length())
		return A < B;
	else if (A.length() > B.length())
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N, pos;
	string name;
	vector<string> names;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		names.resize(N);
		for (int j = 0; j < N; j++)
			cin >> names[j];
		sort(names.begin(), names.end(), cmp);

		cout << "#" << i << "\n";
		cout << names[0] << "\n";
		for (int m = 1; m < names.size(); m++) {
			if (names[m] != names[m - 1])
				cout << names[m] << "\n";
		}
	}
	return 0;
}
