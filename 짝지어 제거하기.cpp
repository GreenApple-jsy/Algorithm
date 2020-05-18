#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	stack<char> st;

	for (int i = 0; i < s.length(); i++) {
		if ((st.size() > 0) && (st.top() == s[i])) //알파벳 짝을 이룬 경우
			st.pop();
		else
			st.push(s[i]);
	}

	if (st.empty())
		return 1;

	return 0;
}
