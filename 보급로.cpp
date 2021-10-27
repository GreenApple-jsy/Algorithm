#include <iostream>
using namespace std;

#define MAX 100
#define QUEUE_MAX 10000

struct info {
	int dist;
	int x;
	int y;
};

int map[MAX][MAX]; //입력받는 보드
int dist[MAX][MAX]; //누적 거리 저장
info p_queue[QUEUE_MAX]; // priority queue
int q_size;
int min_distance;
int N;

//priority queue push
void q_push(info value) {
	if (q_size > QUEUE_MAX)
		return;

	p_queue[q_size] = value;

	int current = q_size;
	while (current > 0 && (p_queue[current].dist < p_queue[(current - 1) / 2].dist)) {
		info temp = p_queue[current];
		p_queue[current] = p_queue[(current - 1) / 2];
		p_queue[(current - 1) / 2] = temp;
		current = (current - 1) / 2;
	}
	q_size++;
}

//priority queue pop
info q_pop() {
	if (q_size <= 0)
		return { -1, 0, 0 };

	info value = p_queue[0];
	q_size--;
	p_queue[0] = p_queue[q_size];

	int current = 0;
	while (current * 2 + 1 < q_size) {
		int child;
		if (current * 2 + 2 == q_size)
			child = current * 2 + 1;
		else
			child = p_queue[current * 2 + 1].dist < p_queue[current * 2 + 2].dist ? current * 2 + 1 : current * 2 + 2;

		if (p_queue[current].dist < p_queue[child].dist)
			break;

		info temp = p_queue[current];
		p_queue[current] = p_queue[child];
		p_queue[child] = temp;
		current = child;
	}
	return value;
}

// 다익스트라 알고리즘
void dijkstra() {
	while (q_size > 0) {
		info i = q_pop();
		int d = i.dist, x = i.x, y = i.y;
		//상
		if (x > 0) {
			x--;
			if (dist[x][y] > d + map[x][y]) {
				dist[x][y] = d + map[x][y];
				if (x == N - 1 && y == N - 1)
					return;
				q_push({ dist[x][y], x, y });
			}
			x++;
		}
		//하
		if (x < N - 1) {
			x++;
			if (dist[x][y] > d + map[x][y]) {
				dist[x][y] = d + map[x][y];
				if (x == N - 1 && y == N - 1)
					return;
				q_push({ dist[x][y], x, y });
			}
			x--;
		}
		//좌
		if (y > 0) {
			y--;
			if (dist[x][y] > d + map[x][y]) {
				dist[x][y] = d + map[x][y];
				if (x == N - 1 && y == N - 1)
					return;
				q_push({ dist[x][y], x, y });
			}
			y++;
		}
		//우
		if (y < N - 1) {
			y++;
			if (dist[x][y] > d + map[x][y]) {
				dist[x][y] = d + map[x][y];
				if (x == N - 1 && y == N - 1)
					return;
				q_push({ dist[x][y], x, y });
			}
			y--;
		}
	}
}
	

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		q_size = 0;
		min_distance = QUEUE_MAX;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				scanf("%1d", &map[i][j]);
				dist[i][j] = QUEUE_MAX;
			}
		}
		dist[0][0] = 0;
		q_push({ 0, 0, 0 });
		dijkstra();
		cout << "#" << tc << " " << dist[N -1][N -1] << endl;
	}
	return 0;
}
