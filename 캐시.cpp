#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
	if (cacheSize == 0)
		return cities.size() * 5;
	vector<string>q;
	int time = 0;
	for (int i = 0; i < cities.size(); i++) {
		int j = 0;
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower); //���� �̸��� �ҹ��ڷ� ��ȯ
		for (j = 0; j < q.size(); j++) {
			if (cities[i] == q[j]) { // hit
				q.erase(q.begin() + j); // hit�� ���� ���� �ֱ� ������� �÷���
				q.push_back(cities[i]);
				time += 1;
				break;
			}
		}
		if (j == q.size()) { // miss
			time += 5;
			if (q.size() >= cacheSize) 
				q.erase(q.begin()); // ĳ�� ����� ���� ��� ���� ������ ����� �� ����
			q.push_back(cities[i]);
		}
	}
	return time;
}