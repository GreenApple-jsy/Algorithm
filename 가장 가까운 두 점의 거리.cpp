#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct Point {
	int x;
	int y;
};

vector <Point>  points;
long long closest_dist;

// 두 점 사이 간의 거리 제곱값
long long dist(Point a, Point b) {
	return (((long long)b.x - a.x) * ((long long)b.x - a.x)) + (((long long)b.y - a.y) * ((long long)b.y - a.y));
}

// x좌표 오름차순 정렬
bool x_cmp(Point a, Point b) {
	if (a.x < b.x)
		return true;

	return false;
}

// Line Sweeping 방식으로 풀이
// 현재 점(idx) 기준으로 x거리 차이가 지금까지 구한 최소 거리보다 작은 점들의 거리만 구함
void find_closest(int idx) {
	double sqrt_dist = sqrt(closest_dist);
	long long d;

	// 현재 점보다 왼쪽에 위치한 점들
	for (int i = idx - 1; i >= 0; --i) {
		if ((double)points[idx].x - points[i].x < sqrt_dist) {
			d = dist(points[idx], points[i]);

			// 최소 거리 갱신
			if (d < closest_dist)
				closest_dist = d;
		}
		else
			break;
	}

	// 현재 점보다 오른쪽에 위치한 점들
	for (int i = idx + 1; i < points.size(); ++i) {
		if ((double)points[i].x - points[idx].x < sqrt_dist) {
			d = dist(points[idx], points[i]);

			// 최소 거리 갱신
			if (d < closest_dist)
				closest_dist = d;
		}
		else
			break;
	}
}

int main() {
	int N;
	cin >> N;
	points.resize(N);
	for (int n = 0; n < N; ++n)
		cin >> points[n].x >> points[n].y;
	sort(points.begin(), points.end(), x_cmp); //x좌표 기준 오름차순으로 정렬
	closest_dist = dist(points[0], points[1]); // 초기 최소 거리 값을 가장 x값이 작은 두 점의 거리로 설정
	for (int i = 0; i < N; ++i)
		find_closest(i);
	cout << closest_dist << endl;	
	return 0;
}
