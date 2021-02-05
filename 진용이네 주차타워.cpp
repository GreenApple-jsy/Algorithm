#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int sum = 0, n, m;
		cin >> n >> m;

		priority_queue<int, vector<int>, greater<int> > available_pos; //주차 가능한 자리(번호 낮은순으로 정렬)
		vector <int> parking_charge(n); //주차 자리별 요금
		for (int j = 0; j < n; j++) {
			cin >> parking_charge[j];
			available_pos.push(j);
		}
			
		vector <pair<int, int>> car_info(m + 1); // <무게, 주차한 자리>
		int w;
		for (int j = 1; j <= m; j++) {
			cin >> w;
			car_info[j] = make_pair(w, -1);
		}

		int car_input;
		queue <int> waiting_cars; //주차 대기 차량(먼저 온 차 우선)
		for (int j = 0; j < m * 2; j++) {
			cin >> car_input;
			if (car_input > 0)
				waiting_cars.push(car_input);
			else if (car_input < 0)
				available_pos.push(car_info[car_input * -1].second);

			//주차 대기 차량과 주차 자리가 있다면 주차시킴
			while (waiting_cars.size() > 0 && available_pos.size() > 0) { 
				int pos = available_pos.top();
				available_pos.pop();
				int car = waiting_cars.front();
				waiting_cars.pop();
				sum += car_info[car].first * parking_charge[pos];
				car_info[car].second = pos;
			}
		}
		cout << "#" << i << " " << sum <<  "\n";
	}
	return 0;
}
