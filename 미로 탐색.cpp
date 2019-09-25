#include <string>
#include <iostream>

using namespace std;
int maze[100][100];
bool check[100][100];
int N, M;
int answer;
void find(int sum, int cn, int cm) {
	check[cn][cm] = true;
	if (cn == N - 1 && cm == M - 1) {
		if (sum < answer)
			answer = sum;
	}
	else if (cn > N - 1 || cm > M - 1)
		return;
	else if (check[cn][cm])
		return;
	else if (maze[cn + 1][cm] == 1) {
		sum++;
		cn++;
		find(cn, cm, sum);
	}
	else if (maze[cn][cm + 1] == 1) {
		sum++;
		cm++;
		find(cn, cm, sum);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> maze[i][j];
	answer = N * M;
	find(0,0,1);
	cout << answer;
}