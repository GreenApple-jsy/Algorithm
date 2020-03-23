#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gn;

bool cmp(string a, string b) { //비교 함수
	if (a[gn] == b[gn]) //지정 인덱스의 문자가 같은 경우 사전순으로 정렬
		return a < b;
	return (a[gn] < b[gn]); //지정 인덱스의 문자 비교
}

vector<string> solution(vector<string> strings, int n) {
	gn = n;
	sort(strings.begin(), strings.end(), cmp);
	return strings;
}