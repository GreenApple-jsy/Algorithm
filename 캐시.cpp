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
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower); //도시 이름을 소문자로 변환
		for (j = 0; j < q.size(); j++) {
			if (cities[i] == q[j]) { // hit
				q.erase(q.begin() + j); // hit한 값을 가장 최근 사용으로 올려줌
				q.push_back(cities[i]);
				time += 1;
				break;
			}
		}
		if (j == q.size()) { // miss
			time += 5;
			if (q.size() >= cacheSize) 
				q.erase(q.begin()); // 캐시 사이즈를 넘을 경우 가장 예전에 사용한 값 삭제
			q.push_back(cities[i]);
		}
	}
	return time;
}