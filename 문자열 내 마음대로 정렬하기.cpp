#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gn;

bool cmp(string a, string b) { //�� �Լ�
	if (a[gn] == b[gn]) //���� �ε����� ���ڰ� ���� ��� ���������� ����
		return a < b;
	return (a[gn] < b[gn]); //���� �ε����� ���� ��
}

vector<string> solution(vector<string> strings, int n) {
	gn = n;
	sort(strings.begin(), strings.end(), cmp);
	return strings;
}