#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector <int> solution(int n, long long k) {
	vector <int> leftp; //줄을 아직 서지 않은 사람들의 번호
	vector <int> answer;
	vector <long long> fac;
	fac.push_back(1);
	for (int i = 1; i <= n - 1; i++) //팩토리얼 수 저장
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