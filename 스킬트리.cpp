#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = skill_trees.size();
	map <char, int> p_skill; // ���� ��ų ��� <���� ��ų ���ĺ�, ��>
	for (int i = 0; i < skill.length(); i++) //���� ��ų�� ���� 1���� ���ʴ�� ����
		p_skill[skill[i]] = i + 1;
	for (int i = 0; i < skill_trees.size(); i++) {
		int current = 0; //���� �ֱ� ��� ���� ��ų�� ��ų��
		for (int j = 0; j < skill_trees[i].length(); j++) {
			int val = p_skill[skill_trees[i][j]];
			if (val == current + 1) //���������� ��ų ��� ���, current �� ����
				current++;
			else if ((val != 0) && (val != current + 1)) { //���������� ��ų�� ����� ���� ���
				answer--; //�Ұ����� ��ųƮ��
				break;
			}
		}
	}
	return answer;
}