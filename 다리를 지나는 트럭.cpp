#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	vector <pair<int, int>> TrucksOnTheBridge; // <Ʈ�� ����, ���� ����>
	int weightSum = 0;
	int time = 0;

	while ((truck_weights.size() > 0) || (TrucksOnTheBridge.size() > 0)) {
		time++;
		weightSum = 0;

		//�ٸ� �� Ʈ������ ���� ���
		for (int i = 0; i < TrucksOnTheBridge.size(); i++) { 
			weightSum += TrucksOnTheBridge[i].first;
		}

		//�ٸ��� ���Ը� �ߵ� �� ���� ��� Ʈ�� ���
		if ((truck_weights.size() > 0) && (weightSum + truck_weights.front() <= weight)) { 
			TrucksOnTheBridge.push_back(make_pair(truck_weights.front(), bridge_length));
			truck_weights.erase(truck_weights.begin());
		}

		//�ٸ� �� Ʈ������ ���� �Ÿ� ����
		for (int i = 0; i < TrucksOnTheBridge.size(); i++) { 
			TrucksOnTheBridge[i].second--;
		}

		//������ Ʈ�� ����
		while ((TrucksOnTheBridge.size() > 0) && (TrucksOnTheBridge.front().second <= 0)) 
			TrucksOnTheBridge.erase(TrucksOnTheBridge.begin());
	}
	return time + 1;
}