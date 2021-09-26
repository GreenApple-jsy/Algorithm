#include <iostream>
using namespace std;

int main() {
	int T, N, dist;
	cin >> T;

	for (int i = 1; i <= T; ++i) {
		cin >> N;
		int min_dist = 100000, same_dist_count = 0; //가장 가까운 위치, 같은 거리인 돌 개수 
		for (int j = 0; j < N; ++j) {
			cin >> dist;
			if (dist < 0) dist *= -1;
			if (dist < min_dist) {
				min_dist = dist;
				same_dist_count = 1;
			}
			else if (dist == min_dist)
				same_dist_count++;
		}
		cout << "#" << i << " " << min_dist << " " << same_dist_count << endl;
	}
	return 0;
}
