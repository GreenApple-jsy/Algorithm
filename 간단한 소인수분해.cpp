#include <iostream>
#include <string>
using namespace std;

int main() {
	int number{ 0 }, q;
	int arr[5] = { 2, 3, 5, 7, 11 };
	int answer[5]{ 0 };

	cin >> number;

	for (int i = 1; i <= number; i++) {
		for (int j = 0; j < 5; j++)
			answer[j] = 0;
		for (int k = 0; k < 5; k++) {
			while ((q % arr[k]) == 0) {
				q /= arr[k];
				answer[k]++;
			}
		}
		cin >> q;
		cout << '#' << i << ' ' << answer[0] << ' ' << answer[1] << ' ' << answer[2] << ' ' << answer[3] << ' ' << answer[4] << endl;
	}
	return 0;
}