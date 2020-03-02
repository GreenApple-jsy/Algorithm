#include<string>
using namespace std;

bool solution(string s)
{
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			sum++;
		else
			sum--;
		if (sum < 0)
			return false;
	}
	if (sum != 0)
		return false;
	return true;
}