#include <iostream>
#include <vector>
#include <string>
using namespace std;

void diffuse(vector <vector <int>> &area, int x, int y) {
	//상
	if (x > 0 && area[x - 1][y] == 0) {
		area[x - 1][y] = 2;
		diffuse(area, x - 1, y);
	}
	//하
	if (x < area.size() - 1 && area[x + 1][y] == 0) {
		area[x + 1][y] = 2;
		diffuse(area, x + 1, y);
	}
	//좌
	if (y > 0 && area[x][y - 1] == 0) {
		area[x][y - 1] = 2;
		diffuse(area, x, y - 1);
	}
	//우
	if (y < area[0].size() - 1 && area[x][y + 1] == 0) {
		area[x][y + 1] = 2;
		diffuse(area, x, y + 1);
	}
}

int cal_safe_area(vector <vector <int>> area, int x1, int y1, int x2, int y2, int x3, int y3) {
	int area_size = 0;
	area[x1][y1] = 1;
	area[x2][y2] = 1;
	area[x3][y3] = 1;
	for (int i = 0; i < area.size(); i++) {
		for (int j = 0; j < area[i].size(); j++) {
			if (area[i][j] == 2) {
				diffuse(area, i, j);
			}
		}
	}
	for (int i = 0; i < area.size(); i++) {
		for (int j = 0; j < area[i].size(); j++) {
			if (area[i][j] == 0)
				area_size++;
		}
	}
	return area_size;
}

int main() {
	vector <vector <int>> area;
	vector <pair <int, int>> zero_pos;
	int h, w;
	int max_safe_area = 0;
	cin >> h >> w;
	area.resize(h);
	for (int i = 0; i < h; i++) {
		area[i].resize(w);
		for (int j = 0; j < w; j++) {
			cin >> area[i][j];
			if (area[i][j] == 0)
				zero_pos.push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < zero_pos.size() - 2; i++) {
		for (int j = i + 1; j < zero_pos.size() - 1; j++) {
			for (int k = j + 1; k < zero_pos.size(); k++) {
				int safe_area = cal_safe_area(area, zero_pos[i].first, zero_pos[i].second,
					zero_pos[j].first, zero_pos[j].second,
					zero_pos[k].first, zero_pos[k].second);

				if (safe_area > max_safe_area)
					max_safe_area = safe_area;
			}
		}
	}

	cout << max_safe_area;
	return 0;
}
