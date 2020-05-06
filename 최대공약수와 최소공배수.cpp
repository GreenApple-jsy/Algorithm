#include <string>
#include <vector>
using namespace std;

int findGCD(int &n, int &m) {
	for (int i = ((n < m) ? n : m); i >= 1; i--) {
		if ((n % i == 0) && (m % i == 0))
			return i;
	}
	return 1;
}

int findLCM(int &n, int &m) {
	int i = (n < m) ? m : n;
	while ((i % n != 0) || (i % m != 0))
		i++;
	return i;
}

vector<int> solution(int n, int m) {
	vector<int> answer;
	answer.push_back(findGCD(n, m)); //�ִ����� ã��
	answer.push_back(findLCM(n, m)); //�ּҰ���� ã��
	return answer;
}