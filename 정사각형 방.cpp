#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rooms;
vector<vector<bool>> visited; //방들의 방문 여부 기록

int visitRoomN(int i, int j, int currentVisitN) {
	int maxVisitN = currentVisitN;
	int n;

	visited[i][j] = true; //현재 방문한 방에 대한 방문표시

	if ((i > 0) && (rooms[i-1][j] == rooms[i][j] + 1)){ //상 방문
		n = visitRoomN(i - 1, j, currentVisitN + 1);
		if (n > maxVisitN)
			maxVisitN = n;
	}

	if ((i < rooms.size() - 1) && (rooms[i + 1][j] == rooms[i][j] + 1)) { //하 방문
		n = visitRoomN(i + 1, j, currentVisitN + 1);
		if (n > maxVisitN)
			maxVisitN = n;
	}

	if ((j > 0) && (rooms[i][j - 1] == rooms[i][j] + 1)) { //좌 방문
		n = visitRoomN(i, j - 1, currentVisitN + 1);
		if (n > maxVisitN)
			maxVisitN = n;
	}

	if ((j < rooms.size() - 1) && (rooms[i][j+1] == rooms[i][j] + 1)) { //우 방문 
		n = visitRoomN(i, j + 1, currentVisitN + 1);
		if (n > maxVisitN)
			maxVisitN = n;
	}

	return maxVisitN;
}

int main() {
	int maxVisitN, maxRoomN;
	string answer = "";
	int T, N, visitN, roomN;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		maxVisitN = 0; maxRoomN = 0;
		cin >> N;
		rooms.resize(N);
		visited.resize(N);
		for (int j = 0; j < N; j++) {
			rooms[j].resize(N);
			visited[j].assign(N, false);
			for (int k = 0; k < N; k++)
				cin >> rooms[j][k];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) { //이전에 방문하지 않은 방인 경우에만 방문
					roomN = rooms[i][j];
					visitN = visitRoomN(i, j, 1);
					if ((visitN > maxVisitN) || ((visitN == maxVisitN) && (roomN < maxRoomN))) {
						maxVisitN = visitN;
						maxRoomN = roomN;
					}
				}
			}
		}
		answer += "#" + to_string(i) + " "  + to_string(maxRoomN) + " " + to_string(maxVisitN) + "\n";
	}
	cout << answer;
	return 0;
}
