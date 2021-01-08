#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int N, A, B;
		cin >> N >> A >> B;
		cout << "#" << i << " "  << min(A, B) << " " << ((N < A + B) ? (A + B - N) :0) << "\n";
	}
	return 0;
}
