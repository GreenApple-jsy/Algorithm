#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//부분 집합 찾기
void find_subset(int pos, string c, string course, vector<string>& courses) {
    if (pos >= c.length()) {
        if (course.length() >= 2) //최소 2가지 이상의 단품메뉴
            courses.push_back(course);
        return;
    }
    find_subset(pos + 1, c, course, courses);
    find_subset(pos + 1, c, course + c[pos], courses);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> courses;

    //각 손님마다 일대일로 공통 메뉴들을 찾음
    for (int i = 0; i < orders.size() - 1; i++) {

        //손님이 시킨 메뉴를 알파벳순으로 정렬
        sort(orders[i].begin(), orders[i].end());

        for (int j = i + 1; j < orders.size(); j++) {
            string c = "";
            for (int k = 0; k < orders[i].length(); k++) {
                if (orders[j].find(orders[i][k]) <= orders[j].length())
                    c += orders[i][k];
            }
            if (c.length() > 1) { //두 손님의 공통 메뉴들로부터 부분집합을 만듦
                find_subset(0, c, "", courses);
            }
        }
    }
    sort(courses.begin(), courses.end());
    courses.erase(unique(courses.begin(), courses.end()), courses.end()); //중복 제거

    vector <pair <string, int>> course_count;

    //각 코스 별로 몇 명의 손님이 주문했는지 확인
    for (int i = 0; i < courses.size(); i++) {
        int c_count = 0;
        for (int j = 0; j < orders.size(); j++) {
            int check = 0;
            for (int k = 0; k < courses[i].length(); k++) {
                if (orders[j].find(courses[i][k]) <= orders[j].length())
                    check++;
            }
            if (check == courses[i].length())
                c_count++;
        }
        course_count.push_back(make_pair(courses[i], c_count));
    }
    vector<string> answer;

    //코스요리 구성 메뉴 개수 별로 가장 많이 주문한 코스를 찾음
    for (int i = 0; i < course.size(); i++) {
        int max_count = 0;
        for (int j = 0; j < course_count.size(); j++) {
            if (course_count[j].first.length() == course[i])
                if (course_count[j].second > max_count)
                    max_count = course_count[j].second;
        }
        for (int j = 0; j < course_count.size(); j++) {
            if (course_count[j].first.length() == course[i])
                if (course_count[j].second == max_count)
                    answer.push_back(course_count[j].first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
