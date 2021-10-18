#include <iostream>
#include <cmath>
using namespace std;

//n개 중에 r개를 뽑는 조합 수 구하기(nCr = n-1Cr-1 + n-1Cr)
int cal_comb(int n, int r) {
	if (r == 0 || n == r)
		return 1;
	else
		return cal_comb(n - 1, r - 1) + cal_comb(n - 1, r);
}

//완제품을 만들 확률 구하기
//(만들 확률^만드는 개수) * (못만들 확률^못만드는 개수) * 18개중 n개 뽑는 경우의 수(18Cn)
double cal_prob(int &prob, int num) {
	return pow(prob / 100.0, num) * pow((100.0 - prob) / 100.0, 18 - num) * cal_comb(18, num);
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		int a, b;
		cin >> a >> b;
		double A_val = 0.0, B_val = 0.0;

		A_val = cal_prob(a, 0) + cal_prob(a, 1) + cal_prob(a, 4)
			+ cal_prob(a, 6) + cal_prob(a, 8) + cal_prob(a, 9)
			+ cal_prob(a, 10) + cal_prob(a, 12) + cal_prob(a, 14)
			+ cal_prob(a, 15) + cal_prob(a, 16) + cal_prob(a, 18);

		B_val = cal_prob(b, 0) + cal_prob(b, 1) + cal_prob(b, 4)
			+ cal_prob(b, 6) + cal_prob(b, 8) + cal_prob(b, 9)
			+ cal_prob(b, 10) + cal_prob(b, 12) + cal_prob(b, 14)
			+ cal_prob(b, 15) + cal_prob(b, 16) + cal_prob(b, 18);

		// 1 - (A와 B 둘 다 소수가 아닌 개수의 완제품을 만들 확률)
		printf("#%d %.6f\n", i, 1.0 - (A_val * B_val));
	}

	return 0;
}
