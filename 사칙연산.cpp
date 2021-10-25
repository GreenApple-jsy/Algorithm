#include <iostream> 
using namespace std;

int tree[1001][3];

int PostOrder(int n) {
	if (!tree[n][1])
		return tree[n][0];

	int x = PostOrder(tree[n][1]);
	int y = PostOrder(tree[n][2]);

	if (tree[n][0] == '+')
		return x + y;
	else if (tree[n][0] == '-')
		return x - y;
	else if (tree[n][0] == '*')
		return x * y;
	else if (tree[n][0] == '/')
		return x / y;
	else			   
		return 0;
}

int main() {
	int N, num;
	char c[20];

	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;

		for (int i = 0; i < 1001; ++i)
			tree[i][1] = tree[i][2] = 0;

		for (int i = 1; i <= N; i++) {
			cin >> num >> c;

			if (c[0] < '0') {
				tree[i][0] = c[0];
				cin >> tree[i][1] >> tree[i][2];
			}
			else {
				int m = 0, j = 0, k = 0;;
				while (k = c[m]) {
					j = j * 10 + k - '0';
					m++;
				}
				tree[i][0] = j;
			}	
		}
		cout << "#" << tc << " " << PostOrder(1) << endl;
	}
	return 0;
}
