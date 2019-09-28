#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int N, int number) {
	if (number == N)
		return 1;
	vector <vector <int>> c;
	c.resize(9);
	for (int t = 1; t < 9; t++) {
		int temp = 0;
		for (int k = 1; k <= t; k++) {
			temp += N * (pow(10, k - 1));
		}
		c[t].push_back(temp);
	}
	for (int i = 2; i < 9; i++) {
		for (int h = 1; h <= i / 2; h++) {
			for (int n = 0; n < c[h].size(); n++) {
				for (int m = 0; m < c[i - h].size(); m++) {
					c[i].push_back(c[h][n] + c[i - h][m]);
					c[i].push_back(c[h][n] - c[i - h][m]);
					c[i].push_back(c[i - h][m] - c[h][n]);
					c[i].push_back(c[h][n] * c[i - h][m]);
					if (c[h][n] != 0)
						c[i].push_back(c[i - h][m] / c[h][n]);
					if (c[i - h][m] != 0)
						c[i].push_back(c[h][n] / c[i - h][m]);
				}
			}
		}
		for (int k = 0; k < c[i].size(); k++) {
			if (c[i][k] == number)
				return i;
		}
	}
	return -1;
}