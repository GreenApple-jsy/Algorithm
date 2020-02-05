#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	vector <pair<int, int>> TrucksOnTheBridge; // <트럭 무게, 남은 길이>
	int weightSum = 0;
	int time = 0;

	while ((truck_weights.size() > 0) || (TrucksOnTheBridge.size() > 0)) {
		time++;
		weightSum = 0;

		//다리 위 트럭들의 무게 계산
		for (int i = 0; i < TrucksOnTheBridge.size(); i++) { 
			weightSum += TrucksOnTheBridge[i].first;
		}

		//다리가 무게를 견딜 수 있을 경우 트럭 출발
		if ((truck_weights.size() > 0) && (weightSum + truck_weights.front() <= weight)) { 
			TrucksOnTheBridge.push_back(make_pair(truck_weights.front(), bridge_length));
			truck_weights.erase(truck_weights.begin());
		}

		//다리 위 트럭들의 남은 거리 감소
		for (int i = 0; i < TrucksOnTheBridge.size(); i++) { 
			TrucksOnTheBridge[i].second--;
		}

		//도착한 트럭 제외
		while ((TrucksOnTheBridge.size() > 0) && (TrucksOnTheBridge.front().second <= 0)) 
			TrucksOnTheBridge.erase(TrucksOnTheBridge.begin());
	}
	return time + 1;
}