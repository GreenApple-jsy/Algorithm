#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
	float i = 0; float u = 0; //교집합, 합집합
	vector <string> vstr1, vstr2;
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper); //대문자 변환
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	for (int i = 0; i < str1.length() - 1; i++) {
		if (isalpha(str1[i]) && isalpha(str1[i + 1])) //알파벳인 경우만 원소로 취급
			vstr1.push_back(str1.substr(i, 2));
	}
	for (int i = 0; i < str2.length() - 1; i++) {
		if (isalpha(str2[i]) && isalpha(str2[i + 1]))
			vstr2.push_back(str2.substr(i, 2));
	}
	if (vstr1.size() == 0 && vstr2.size() == 0) //둘 다 공집합인 경우
		return 65536;
	sort(vstr1.begin(), vstr1.end()); //사전순으로 정렬
	sort(vstr2.begin(), vstr2.end());
	int m = 0; int n = 0; //두 집합의 비교 인덱스
	while (m < vstr1.size() && n < vstr2.size()) {
		if (vstr1[m] == vstr2[n]) { //교집합 & 합집합에 추가
			i++; u++;
			m++; n++;
		}
		else if (vstr1[m] > vstr2[n]) { //합집합에 추가
			u++;
			n++;
		}
		else if (vstr1[m] < vstr2[n]) { //합집합에 추가
			u++;
			m++;
		}
	}
	u += vstr1.size() - m; //남은 원소를 합집합에 넣음
	u += vstr2.size() - n;
	return int(i / u * 65536);
}