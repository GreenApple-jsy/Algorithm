#include <string>
#include <vector>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 0; j < i; j++) { //이전 전화번호들과 비교
            int cmp_length = (phone_book[i].length() < phone_book[j].length()) ? phone_book[i].length() : phone_book[j].length(); //비교할 문자열 길이
            if (phone_book[i].substr(0, cmp_length) == phone_book[j].substr(0, cmp_length)) {
                return false;
            }
        }
    }
    return answer;
}
