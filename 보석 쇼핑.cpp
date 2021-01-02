#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> gem_map; //key-보석, value-보석 포함 개수
    set <string> gem_set(gems.begin(), gems.end()); //중복 원소 제외 저장
    int unique_gem_count = gem_set.size();
    int minDist, start = 0, end = gems.size() - 1;

    for (int index = 0; index < gems.size(); index++) {
        gem_map[gems[index]]++;
        if (gem_map.size() >= unique_gem_count) { //모든 보석을 포함하는 지점을 찾음
            end = index;
            break;
        }
    }

    answer = { start + 1, end + 1 };
    minDist = end - start;

    while (end < gems.size()) {
        string gem = gems[start];
        gem_map[gem]--;
        start++; //start포인트를 증가시켜가며 가장 짧은 구간 검색

        if (gem_map[gem] == 0) { //구간에 포함된 보석 개수가 0이라면
            end++; //end포인트 증가
            while (end < gems.size()) {
                gem_map[gems[end]]++;
                if (gems[end] == gem)
                    break;
                end++; //해당 보석이 나올 때까지 end포인트 증가
            }
        }
        if (end - start < minDist) {
            answer = { start + 1, end + 1 };
            minDist = end - start;
        }
    }
    return answer;
}
