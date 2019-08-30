#include <iostream>
#include <string>
using namespace std;

int cal(int tc) {
	bool check[10]{ false };
	int answer{ 0 };

	while (tc >= 10) {
		check[tc % 10] = true;
		tc = tc / 10;
	}
	check[tc] = true;

	for (int i = 0; i < 10; i++) {
		if (check[i])
			answer++;
	}
	return answer;
}

int main() {
	int number{ 0 }, tc;
	cin >> number;
	for (int i = 1; i <= number; i++) {
		cin >> tc;
		cout << '#' << i << ' ' << cal(tc) << endl;
	}
	return 0;
}