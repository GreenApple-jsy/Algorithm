#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
	int max = 0;
	int fson, sson = 0;
	int sum[2000]; int halfsum;
	sum[0] = cookie[0];
	for (int i = 1; i < cookie.size(); i++) //1���� i�� �ٱ��ϱ����� ���� ���� �� ����
		sum[i] = sum[i - 1] + cookie[i];
	halfsum = sum[cookie.size() - 1] / 2; //��ü ���� ������ ��
	for (int f = 0; f < cookie.size() - 1; f++) {
		for (int g = 1; g < cookie.size() - f; g++) {
			if (f == 0)
				fson = sum[f + g - 1];
			else
				fson = sum[f + g - 1] - sum[f - 1];
			if (fson > halfsum) //ù° �Ƶ� ���� ������ ��ü ������ ���� �ʰ��Ͽ����� Ȯ��
				break;
			if (fson > max) { //ù° �Ƶ��� ���� ������ ���� max������ ū ���� ��쿡�� Ȯ��
				for (int i = f + g; i < cookie.size(); i++) {
					sson = sum[i] - sum[f + g - 1];
					if (sson >= fson) {
						if (fson == sson) //ù° �Ƶ�� ��° �Ƶ��� ���� ������ ���� ��� max ����
							max = fson;
						break;
					}
				}
			}
		}
	}
	return max;
}