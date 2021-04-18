#include <iostream>
#include <vector>
using namespace std;

int board[101][101] = { 0, };

void curve(vector<pair<int, int>> points, int cur_gen, int target_gen) {
	if (cur_gen >= target_gen)
		return;
	int last_x = points.back().first, last_y = points.back().second;
	vector<pair<int, int>> curve_points = points;

	//끝점을 시작으로 하여 연결된 점과의 x, y 차이를 구하여 계산
	for (int i = points.size() - 2; i >= 0; i--){
		curve_points.push_back(
			{ last_x - (points[i].second - points[i + 1].second),
			last_y + (points[i].first - points[i + 1].first) });
		last_x -= points[i].second - points[i + 1].second;
		last_y += points[i].first - points[i + 1].first;
		board[last_x][last_y] = 1;  //보드에 커브 꼭지점 체크
	}
	curve(curve_points, cur_gen + 1, target_gen);
	return;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		int x1 = x, y1 = y;
		switch (d) { //시작 방향
		case 0:
			x1++;
			break;
		case 1:
			y1--;
			break;
		case 2:
			x1--;
			break;
		case 3:
			y1++;
			break;
		}
		board[x][y] = 1; board[x1][y1] = 1; //보드에 커브 꼭지점 체크
		curve({{x,y},{x1,y1}}, 0, g);
	}

	int answer = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] == 1
				&& board[i + 1][j] == 1
				&& board[i][j + 1] == 1
				&& board[i + 1][j + 1] == 1)
				answer++;
		}
	}
	cout << answer;
	return 0;
}
