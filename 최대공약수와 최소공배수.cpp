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
	answer.push_back(findGCD(n, m)); //최대공약수 찾기
	answer.push_back(findLCM(n, m)); //최소공배수 찾기
	return answer;
}