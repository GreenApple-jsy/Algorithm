#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	string answer, temp;
	int T, minN, maxN, sum; //테스트케이스 개수, 최소값, 최대값, 합
	cin >> T;
	for (int i = 1; i <= T; i++) {
		minN = 54; //최소값 초기화
		maxN = 1; //최대값 초기화
		for (int j = 0; j < 10; j++) {
			sum = 0;
			cin >> temp;
			for (int k = 0; k < temp.length(); k++)
				sum += temp[k] - 48;
			if (sum > maxN)
				maxN = sum;
			if (sum < minN)
				minN = sum;
		}
		answer += "#" + to_string(i) + " " + to_string(maxN) + " " + to_string(minN) + "\n";
	}
	cout << answer;
	return 0;
}
