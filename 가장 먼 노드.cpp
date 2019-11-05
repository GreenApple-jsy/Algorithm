#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> infoOne; //�� ��帶�� 1�� ������ �Ÿ� ����

void bfs(int current, vector<vector<int>> &connection, vector<int> q) {
	vector <int> nq;
	while (!q.empty()) {
		int num = q.front();
		q.erase(q.begin());
		for (int i = 2; i < connection.size(); i++) {
			if ((connection[num][i] == 1) && (infoOne[i] == 0)) {
				infoOne[i] = current;
				nq.push_back(i);
			}
		}
	}
	if (!nq.empty())
		bfs(current + 1, connection, nq);
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	infoOne.resize(n + 1);
	vector<vector<int>> connection(n + 1, vector<int>(n + 1));
	fill(infoOne.begin(), infoOne.end(), 0);
	for (int i = 0; i < edge.size(); i++) { //����� ���ἱ ����
		connection[edge[i][0]][edge[i][1]] = 1;
		connection[edge[i][1]][edge[i][0]] = 1;
	}
	bfs(1, connection, { 1 });
	int m = *max_element(infoOne.begin(), infoOne.end());
	for (int i = 1; i < infoOne.size(); i++)
		if (infoOne[i] == m)
			answer++;
	return answer;
}