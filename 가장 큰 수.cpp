#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//�� ���ڸ� �̾�ٿ��� ��, �� ū ���� �Ǵ� �������� sort
bool cmp(const string &a, const string &b) {
	return ((a + b) > (b + a));
}

string solution(vector<int> numbers) {
	vector<string> str_vec;
	string answer = "";
	for (int i = 0; i < numbers.size(); i++) {
		str_vec.push_back(to_string(numbers[i]));
	}
	sort(str_vec.begin(), str_vec.end(), cmp);
	for (int i = 0; i < str_vec.size(); i++) {
		answer += str_vec[i];
	}
	//numbers ��Ұ� 0��θ� �̷���� ���� ��� 0�� ����
	if (answer.front() == '0')
		return "0";
	return answer;
}