#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    int s_length = s.length();
    string temp = "";
    for (int i = 0; i < s_length; i++) {
        temp = s.substr(i, s_length - i) + s.substr(0, i);
        stack <int> stk;
        for (int j = 0; j < s_length; j++) {
            if ((stk.size() > 0) && (temp[j] - stk.top()) > 0 && (temp[j] - stk.top()) <= 2) //맞는 괄호 짝인 경우
                stk.pop();
            else
                stk.push(temp[j]);
        }
        if (stk.size() == 0)
            answer++;
    }
    return answer;
}
