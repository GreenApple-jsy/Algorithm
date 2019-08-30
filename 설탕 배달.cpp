#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, x, best{ -1 };
	cin >> N;

	for (x = N / 5; x >= 0; x--) {
		if ((N - (5 * x)) % 3 == 0) {
			best = x + (N - (5 * x)) / 3;
			break;
		}
	}
	cout << best;
}