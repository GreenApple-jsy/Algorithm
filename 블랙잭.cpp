#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N, M, x, y;
	vector <int> vec;
	int best{ 0 };
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x;
		vec.push_back(x);
	}
	for (int i = 0; i <= N - 3; i++) {
		for (int j = i + 1; j <= N - 2; j++) {
			for (int k = j + 1; k <= N - 1; k++) {
				y = vec[i] + vec[j] + vec[k];
				if (y <= M) {
					if (y >= best)
						best = y;
				}
			}
		}
	}
	cout << best;
}