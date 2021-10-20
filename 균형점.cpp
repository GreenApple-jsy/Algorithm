#include <iostream>
#include <cmath>
using namespace std;

int N; //자성체 개수
double x[10], weight[10]; //좌표, 무게 배열

//두 자성체 사이의 균형점 위치 찾기
void find_val_point(int index, double x1, double x2) {
	double mid, cal;
	int count = 100; //계산 반복 횟수

	//이분탐색 반복
	while (count > 0) {
		cal = 0;
		mid = (x1 + x2) / 2.0;

		for (int i = 0; i <= index; ++i)
			cal += weight[i] / ((x[i] - mid) * (x[i] - mid));

		for (int i = index + 1; i < N; ++i)
			cal -= weight[i] / ((x[i] - mid) * (x[i] - mid));

		//오차 허용
		if (abs(cal) <= pow(10,-13))
			break;

		else if (cal > 0)
			x1 = mid;

		else if (cal < 0)
			x2 = mid;

		--count;
	}
	printf(" %.10f", mid);
}

int main() {
	int T;;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> N;

		//자성체 좌표 저장
		for (int j = 0; j < N; ++j)
			cin >> x[j];

		//자성체 무게 저장
		for (int j = 0; j < N; ++j)
			cin >> weight[j];

		printf("#%d", i);
		for (int j = 0; j < N - 1; ++j)
			find_val_point(j, x[j], x[j + 1]);
		printf("\n");
	}
	return 0;
}
