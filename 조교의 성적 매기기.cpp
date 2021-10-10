#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int T, N, K;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		vector <pair <int, int> > score; // <총점, 학생 번호>
		cin >> N >> K;
		for (int j = 1; j <= N; ++j) {
			int mid, fin, work;
			cin >> mid >> fin >> work;
			score.push_back({ ((mid * 35) + (fin * 45) + (work * 20)), j });
		}
		sort(score.begin(), score.end());
		for (int j = 1; j <= N; ++j) {
			if (score[j].second == K) {
				int rate = (double)j / N * 100;

				if (rate < 10)
					cout << "#" << i << " " << "D0" << endl;
				else if (rate < 20)
					cout << "#" << i << " " << "C-" << endl;
				else if (rate < 30)
					cout << "#" << i << " " << "C0" << endl;
				else if (rate < 40)
					cout << "#" << i << " " << "C+" << endl;
				else if (rate < 50)
					cout << "#" << i << " " << "B-" << endl;
				else if (rate < 60)
					cout << "#" << i << " " << "B0" << endl;
				else if (rate < 70)
					cout << "#" << i << " " << "B+" << endl;
				else if (rate < 80)
					cout << "#" << i << " " << "A-" << endl;
				else if (rate < 90)
					cout << "#" << i << " " << "A0" << endl;
				else
					cout << "#" << i << " " << "A+" << endl;

				break;
			}
		}
	}
	return 0;
}
