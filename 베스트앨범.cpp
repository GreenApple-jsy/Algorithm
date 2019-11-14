#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int>genres_count;
	vector <pair<string, int>> v;

	for (int i = 0; i < genres.size(); i++) //�帣 �� ���Ƚ�� ī��Ʈ
		genres_count[genres[i]] += plays[i];
	map<string, int>::iterator iter = genres_count.begin();
	for (iter = genres_count.begin(); iter != genres_count.end(); ++iter) //sort�� ���� ���� ���Ϳ� ����
		v.push_back(make_pair(iter->first, iter->second));

	sort(v.begin(), v.end(), cmp); //��� Ƚ�� �������� ��Ʈ
	for (int i = 0; i < v.size(); i++) { //�帣 ��, ���� ����� �� �� ã��
		int f = 0; int s = 0; int fn = 0; int sn = 0;
		for (int j = 0; j < genres.size(); j++) {
			if (genres[j] == v[i].first) {
				if (plays[j] > f) {
					s = f;
					sn = fn;
					f = plays[j];
					fn = j;
				}
				else if (plays[j] > s) {
					s = plays[j];
					sn = j;
				}
			}
		}
		answer.push_back(fn);
		if (s > 0) //�帣�� 2�� �̻��� ���� ���� ��쿡�� �ٹ��� �ֱ�
			answer.push_back(sn);
	}
	return answer;
}