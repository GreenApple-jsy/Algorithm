#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> courses;
    for (int i = 0; i < orders.size() - 1; i++) {
        sort(orders[i].begin(), orders[i].end());
        for (int j = i + 1; j < orders.size(); j++) {
            string c = "";
            for (int k = 0; k < orders[i].length(); k++) {
                if (orders[j].find(orders[i][k]) <= orders[i].length())
                    c += orders[i][k];
            }
            
            if (c.length() > 1) {
                courses.push_back(c);
                cout << i+1 << "랑 " << j + 1 << "  " << c << endl;
            }
                
        }
    }
    cout << "\n\n";
    sort(courses.begin(), courses.end());
    
    
    courses.erase(unique(courses.begin(), courses.end()), courses.end());
    for (int j = 0; j < courses.size(); j++) {
        cout << courses[j] << ", ";
    }
    cout << "\n\n";

    vector <pair <string, int>> course_count;
    for (int i = 0; i < courses.size(); i++) {
        int c_count = 0;
        for (int j = 0; j < orders.size(); j++) {
            int check = 0;
            for (int k = 0; k < courses[i].length(); k++) {
                int a = orders[j].find(courses[i][k]);
                if (orders[j].find(courses[i][k]) <= orders[j].length())
                    check++;
            }
            if (check == courses[i].length())
                c_count++;
        }
        course_count.push_back(make_pair(courses[i], c_count));
    }

    for (int i = 0; i < course_count.size(); i++) {
        cout << course_count[i].first << ", " << course_count[i].second << endl;
    }
    cout << "\n\n";


    vector<string> answer;
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

    for (int j = 0; j < answer.size(); j++) {
        cout << answer[j] << ", ";
    }

    return answer;
}

int main() {

    //solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
    //solution({ "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" }, { 2,3,5 });
    solution({ "ABC", "ABC"}, { 2,3});
}
