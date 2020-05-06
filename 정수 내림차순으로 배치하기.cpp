#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
	string temp = to_string(n);
	sort(temp.begin(), temp.end(), greater<char>()); //string 내림차순 정렬
	return stoll(temp); //string -> long long 변환
}
