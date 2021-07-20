#include <iostream>
#include <string>
using namespace std;

//자릿수 계산
int cal_numSize(int N) {
	int count = 1;
	while (N >= 10) {
		N /= 10;
		count++;
	}
	return count;
}

//수의 앞 세자리 구하기
int divide_until_1000(int N) {
	while (N >= 1000)
		N /= 10;
	return N;
}

/*
1, 2, 5
10, 20, 25, 50
100, 125, 200, 250, 500
이 이후로는 뒤에 0만 더 붙이면 된다

1000, 1250, 2000, 2500, 5000
10000, 12500, 20000, 25000, 50000
. . .
*/
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, num_count;
		cin >> N;
		if (N < 2)
			num_count = 1;
		else if (N < 5)
			num_count = 2;
		else if (N < 10)
			num_count = 3;
		else if (N < 20)
			num_count = 4;
		else if (N < 25)
			num_count = 5;
		else if (N < 50)
			num_count = 6;
		else if (N < 100)
			num_count = 7;
		else {
			num_count = 8 + ((cal_numSize(N) - 3) * 5);

			int front_num = divide_until_1000(N);

			if (front_num >= 500)
				num_count += 4;
			else if (front_num >= 250)
				num_count += 3;
			else if (front_num >= 200)
				num_count += 2;
			else if (front_num >= 125)
				num_count += 1;
		}
		cout << "#" << i + 1 << " " << num_count << endl;
	}
	return 0;
}
