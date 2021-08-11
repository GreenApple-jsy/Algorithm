#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;

    //각 숫자 영단어의 앞 두글자와 글자수를 저장함
    vector <pair<string, int> > num_word = { {"ze", 4}, {"on", 3}, {"tw", 3}, {"th", 5}, {"fo", 4}, {"fi", 4}, {"si", 3}, {"se", 5}, {"ei", 5}, {"ni", 4}};
    for (int i = 0; i < s.length(); i++) {
        //숫자인 경우
        if (isdigit(s[i])) {
            answer = (answer * 10) + (s[i] - 48);
        }
        //영단어인 경우
        else {
            for (int j = 0; j < 10; j++) {
                if (s.substr(i, 2) == num_word[j].first) {
                    answer = (answer * 10) + j;
                    i += num_word[j].second - 1;
                    break;
                }
            }
        }
    }
    return answer;
}
