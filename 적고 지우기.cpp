#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string answer = "";
	string input;
	int T, n, temp, start;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		n = 0;
		cin >> input;
		sort(input.begin(), input.end()); //숫자들을 오름차순으로 정렬
		for (int j = 0; j < input.length(); j++) {
			temp = 0;
			start = j;
			while (input[j] == input[start]) {
				temp++;
				j++;
			}
			if (temp % 2 != 0) //같은 수가 홀수  개 있을 경우 카운트해준다
				n++;
			j--;
		}
		answer += "#" + to_string(i) + " " + to_string(n) + "\n";
	}
	cout << answer;
	return 0;
}
