#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct Point {
	int x;
	int y;
};

vector <Point> points;
Point first;

// 점 𝑟을 기준으로 반시계 방향이면 양수, 시계방향이면 음수, 평행이면, 0 리턴
int ccw(Point a, Point b, Point c) {
	long long cal = ((long long)a.x * b.y + (long long)b.x * c.y + (long long)c.x * a.y) - ((long long)b.x * a.y + (long long)c.x * b.y + (long long)a.x * c.y);
	if (cal > 0)
		return 1;
	else if (cal < 0)
		return -1;
	return 0;
}

// 두 점 간의 거리 계산
long long dist(Point a, Point b) {
	return (((long long)b.x - a.x) * ((long long)b.x - a.x)) + (((long long)b.y - a.y) * ((long long)b.y - a.y));
}

// y좌표 오름차순 정렬(y 좌표 동일시 x 좌표 오름차순 정렬)
bool y_cmp(Point a, Point b) {
	if (a.y < b.y)
		return true;
	else if (a.y == b.y) {
		if (a.x < b.x)
			return true;
	}
	return false;
}

// 반시계방향으로 정렬
bool anticlockwise(Point a, Point b) {
	int c = ccw(first, a, b);
	if (c > 0)
		return true;
	else if (c < 0)
		return false;
	else if (dist(first, a) > dist(first, b))
		return false;

	return true;
}

void ConvexHull(stack <Point> &st) {
	sort(points.begin(), points.end(), y_cmp);
	first = points.front();
	
	sort(points.begin(), points.end(), anticlockwise);
	st.push(first);
	for (int i = 1; i < points.size(); ++i) {
		Point top = {}, sec = {};
		if (st.size() > 1) {
			top = st.top();
			st.pop();
			sec = st.top();
			st.push(top);
		}
		while (st.size() > 1 && ccw(sec, top, points[i]) <= 0) {
			st.pop();
			if (st.size() > 1) {
				top = st.top();
				st.pop();
				sec = st.top();
				st.push(top);
			}
		}
		st.push(points[i]);
	}
}

int main() {
	int T, N;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		stack <Point> st;
		cin >> N;
		points.resize(N);
		for (int n = 0; n < N; ++n)
			cin >> points[n].x >> points[n].y;
		ConvexHull(st);
		cout << "#" << tc << " " << st.size() << endl;
	}

	return 0;
}
