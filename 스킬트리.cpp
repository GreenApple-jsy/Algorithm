#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = skill_trees.size();
	map <char, int> p_skill; // 선행 스킬 목록 <선행 스킬 알파벳, 값>
	for (int i = 0; i < skill.length(); i++) //선행 스킬의 값을 1부터 차례대로 저장
		p_skill[skill[i]] = i + 1;
	for (int i = 0; i < skill_trees.size(); i++) {
		int current = 0; //가장 최근 배운 선행 스킬의 스킬값
		for (int j = 0; j < skill_trees[i].length(); j++) {
			int val = p_skill[skill_trees[i][j]];
			if (val == current + 1) //순차적으로 스킬 배운 경우, current 값 갱신
				current++;
			else if ((val != 0) && (val != current + 1)) { //순차적으로 스킬을 배우지 않은 경우
				answer--; //불가능한 스킬트리
				break;
			}
		}
	}
	return answer;
}