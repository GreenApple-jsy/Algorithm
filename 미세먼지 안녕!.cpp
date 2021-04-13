#include <iostream>
#include <vector>
using namespace std;

//인접한 방향에 공기청정기가 있거나,
//칸이 없으면 그 방향으로는 확산이 일어나지 않는다

//확산되는 양은 Ar,c/5이고 소수점은 버린다
//(r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 
int main() {
	int R, C, T;
	cin >> R >> C >> T;
	vector <vector<int>> board;
	for (int i = 0; i < R; i++) {
		vector <int> t(C, 0);
		board.push_back(t);
	}

	return 0;
}
