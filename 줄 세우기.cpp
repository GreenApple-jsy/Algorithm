#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > orders;
int check[32002];

int main() {
	int N, M;
  cin >> N >> M;
  queue<int> q;
  vector<int> cal;
  orders.clear();
  orders.resize(N + 1);

	for (int i = 0; i < 32002; ++i)
       check[i] = 0;

  for (int i = 0; i < M; ++i) {
       int a, b;
       cin >> a >> b;
       orders[a].push_back(b);
       check[b]++;
  }

  for (int i = 1; i <= N; ++i) {
       if (!check[i])
           q.push(i);
  }

        while (!q.empty()) {
            int here = q.front();
            q.pop();

            cal.push_back(here);

            for (int i = 0; i < orders[here].size(); i++) {
                int next = orders[here][i];

                check[next]--;
                if (!check[next])
                    q.push(next);
            }
        }
    
        for (int i = 1; i <= N; i++)
            cout << cal[i - 1] << " ";
        cout << "\n";	
	return 0;    
}
