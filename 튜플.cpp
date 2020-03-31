#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool size_cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector <vector<int>> numbers;
    vector <int> temp;
    string numberString = "";
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == ',') {
            temp.push_back(atoi(numberString.c_str()));
            numberString = "";
        }
        else if (s[i] == '{') {
            //
        }
        else if (s[i] == '}') {
            temp.push_back(atoi(numberString.c_str()));
            numberString = "";
            numbers.push_back(temp);
            temp.clear();
            i++; // '}' 바로 다음에 나오는 ',' 무시하기 위함
        }
        else {
            numberString += s[i];
        }
    }

    sort(numbers.begin(), numbers.end(), size_cmp); //배열 원소 수에 맞춰 정렬

    for (int i = 0; i < numbers.size(); i++) {
        sort(numbers[i].begin(), numbers[i].end());
    }

    answer.push_back(numbers[0][0]);

    for (int i = 1; i < numbers.size(); i++) {
        int j = 0;
        //추가된 원소를 찾아 넣음
        for (j = 0; j < numbers[i - 1].size(); j++) {
            if (numbers[i - 1][j] != numbers[i][j]) {
                answer.push_back(numbers[i][j]);
                break;
            }
        }
        if (j == numbers[i - 1].size()) {
            answer.push_back(numbers[i].back());
        }
    }
    return answer;
}
