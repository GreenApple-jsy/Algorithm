#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		string S;
		cin >> S;
		string A(S, 0, 1);
		for (int j = 1; j < 30; j++) {
			if (A == S.substr(j, A.length())) {
				cout << "#" << i << " " << A.length() << "\n";
				break;
			}
			else {
				A += S[j];
			}	
		}
	}
	return 0;
}
