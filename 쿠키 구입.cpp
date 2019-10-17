#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
	int max = 0;
	int fson, sson = 0;
	int sum[2000]; int halfsum;
	sum[0] = cookie[0];
	for (int i = 1; i < cookie.size(); i++) //1부터 i번 바구니까지의 과자 개수 합 저장
		sum[i] = sum[i - 1] + cookie[i];
	halfsum = sum[cookie.size() - 1] / 2; //전체 과자 개수의 반
	for (int f = 0; f < cookie.size() - 1; f++) {
		for (int g = 1; g < cookie.size() - f; g++) {
			if (f == 0)
				fson = sum[f + g - 1];
			else
				fson = sum[f + g - 1] - sum[f - 1];
			if (fson > halfsum) //첫째 아들 과자 개수가 전체 개수의 반을 초과하였는지 확인
				break;
			if (fson > max) { //첫째 아들의 과자 개수가 현재 max값보다 큰 값일 경우에만 확인
				for (int i = f + g; i < cookie.size(); i++) {
					sson = sum[i] - sum[f + g - 1];
					if (sson >= fson) {
						if (fson == sson) //첫째 아들과 둘째 아들의 과자 개수가 같을 경우 max 갱신
							max = fson;
						break;
					}
				}
			}
		}
	}
	return max;
}