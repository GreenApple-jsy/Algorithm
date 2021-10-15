#include <iostream>
#include <vector>
using namespace std;

vector <vector<int> > relation;
vector <bool> virus_check;

void DFS(int comNum) {
	if (virus_check[comNum] == true)
		return;

	virus_check[comNum] = true;
	for (int i = 0; i < relation[comNum].size(); ++i) {
		DFS(relation[comNum][i]);
	}
	return;
}


int main() {
	int com, pairN;
	cin >> com >> pairN;
	relation.resize(com + 1);
	virus_check.resize(com + 1, false);
	for (int i = 0; i < pairN; ++i) {
		int aCom, bCom;
		cin >> aCom >> bCom;
		relation[aCom].push_back(bCom);
		relation[bCom].push_back(aCom);
	}
	DFS(1);

	int answer = 0;
	for (int i = 2; i <= com; ++i) {
		if (virus_check[i] == true)
			answer++;
	}
	cout << answer;
	return 0;
}
