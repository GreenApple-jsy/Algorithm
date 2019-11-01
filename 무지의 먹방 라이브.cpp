#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
	vector<pair<int, int>> food_info; //<�ɸ��� �ð�, ����>
	long long lastTime = 0; //�ٷ� ���� �˻��� ������ �ɸ��� �ð�
	long long t = 0;
	int size = food_times.size();

	for (int i = 0; i < food_times.size(); i++)
		food_info.push_back(make_pair(food_times[i], i + 1));

	sort(food_info.begin(), food_info.end()); //�ҿ� �ð��� ª�� ���ĺ��� �˻� ����

	for (vector<pair<int, int>>::iterator i = food_info.begin(); i != food_info.end(); i++, size--) {
		t = (i -> first - lastTime) * size; 
		if (t <= k) {
			k -= t; //���� �ð� ����
			lastTime = i->first;
		}
		else {
			sort(i, food_info.end(), compare); //���� ��ȣ������ �ٽ� ����
			return (i + (k % size)) -> second;
		}
	}
	return -1;
}