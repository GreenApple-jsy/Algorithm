#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector <int> solution(int n, long long k) {
	vector <int> leftp; //���� ���� ���� ���� ������� ��ȣ
	vector <int> answer;
	vector <long long> fac;
	fac.push_back(1);
	for (int i = 1; i <= n - 1; i++) //���丮�� �� ����
		fac.push_back(i * fac[i - 1]);
	for (int j = 1; j <= n; j++)
		leftp.push_back(j);
	for (int h = 0; h < n; h++) {
		answer.push_back(leftp[ceil(k / (double)fac[n - h - 1]) - 1]);
		leftp.erase(leftp.begin() + ceil(k / (double)fac[n - h - 1]) - 1);
		k %= fac[n - h - 1];
		if (k == 0)
			k = fac[n - h - 1];
	}
	return answer;
}