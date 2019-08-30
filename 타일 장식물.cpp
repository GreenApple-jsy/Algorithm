#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
	long long tiles[81];
	tiles[0] = 0;
	tiles[1] = 1;
	tiles[2] = 1;
	if (N == 1)
		return 4;
	else if (N == 2)
		return 6;
	else {
		for (int i = 3; i <= N; i++) {
			tiles[i] = tiles[i - 1] + tiles[i - 2];
		}
		return 4 * tiles[N] + 2 * tiles[N - 1];
	}
}