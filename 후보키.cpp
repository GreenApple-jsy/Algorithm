#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//속성들로 만들 수 있는 부분집합들 <속성 개수, 속성 종류(마지막 원소는 NeedCheck)>
vector<pair<int, vector<bool>>> subset;
int ck; //후보키 개수

//dfs로 부분 집합 찾기 (각 부분집합의 원소 개수를 저장하기 위해 element_count 변수 추가)
void find_subset(int columnsize, int element_count, vector <bool> subset_element) {
    if (subset_element.size() >= columnsize) {
        subset_element.push_back(true); //후보키인지 확인을 위한 bool 추가(NeedCheck)
        if (element_count > 0) //공집합 제외
            subset.push_back(make_pair(element_count, subset_element));
        return;
    }
    subset_element.push_back(false);
    find_subset(columnsize, element_count, subset_element);
    subset_element.back() = true;
    find_subset(columnsize, element_count + 1, subset_element);
}

//후보키 찾기
void find_ck(vector<vector<string>> relation) {
    for (int i = 0; i < subset.size(); i++) {
        if (subset[i].second.back() == true) { //후보키인지 확인이 필요한 경우(NeedCheck가 true인 경우)
            
            //부분집합의 원소 종류 저장
            vector <int> element_pos; 
            for (int j = 0; j < relation[0].size(); j++) {
                if (subset[i].second[j] == true)
                    element_pos.push_back(j);
            }

            //해당되는 속성들의 값만 이어붙여 하나의 문자열 s를 생성 후 set에 삽입(중복 문자열은 저장되지 않음)
            set <string> s_set;
            for (int k = 0; k < relation.size(); k++) {
                string s = "";
                for (int j = 0; j < element_pos.size(); j++)
                    s += relation[k][element_pos[j]];
                s_set.insert(s);
            }

            if (s_set.size() == relation.size()) { //후보키인 경우(중복없이 모두 유일한 튜플일 경우)
                ck++;

                //이 부분집합을 포함하고 있는 다른 부분집합들의 NeedCheck를 false 처리
                for (int m = i + 1; m < subset.size(); m++) {
                    int same_element_count = 0;
                    for (int n = 0; n < element_pos.size(); n++) {
                        if (subset[m].second[element_pos[n]] == true)
                            same_element_count++;
                    }
                    if (same_element_count == element_pos.size())
                        subset[m].second.back() = false;
                }
            }
        }
    }
}

int solution(vector<vector<string>> relation) {
    ck = 0;
    find_subset(relation[0].size(), 0, {});
    sort(subset.begin(), subset.end()); //부분 집합들을 원소 개수 순으로 정렬(오름차순)
    find_ck(relation);
    return ck;
}
