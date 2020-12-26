#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T , c, A_length, B_length, pos;
	string A, B;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> A >> B;
		pos = 0; c = 0;
		A_length = A.length();
		B_length = B.length();
		while (pos < A_length) {
			if ((pos <= A_length - B_length) && (A.substr(pos, B_length) == B))
				pos += B_length;
			else
				pos++;
			c++;
		}
		cout << "#" << i << " " << c << "\n";
	}
	return 0;
}
