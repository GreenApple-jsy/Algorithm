#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, count;
	string tc;
	string name[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		int num_count[10] = { 0, };
		string s;
		cin >> tc >> count;
		for (int j = 0; j < count; ++j) {
			cin >> s;
			if (s == name[0])
				num_count[0]++;
			else if (s == name[1])
				num_count[1]++;
			else if (s == name[2])
				num_count[2]++;
			else if (s == name[3])
				num_count[3]++;
			else if (s == name[4])
				num_count[4]++;
			else if (s == name[5])
				num_count[5]++;
			else if (s == name[6])
				num_count[6]++;
			else if (s == name[7])
				num_count[7]++;
			else if (s == name[8])
				num_count[8]++;
			else if (s == name[9])
				num_count[9]++;
		}
		cout << "#" << i << endl;
		for (int num = 0; num <= 9; ++num) {
			for (int j = 0; j < num_count[num]; ++j)
				cout << name[num] << " ";
		}
		cout << "\n";
	}

	return 0;
}
