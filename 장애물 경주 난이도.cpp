#include <string>
#include <iostream>
using namespace std;

int main() {
	string answer;
	int T, N, n1, n2, upD, downD, temp;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		upD = 0;
		downD = 0;
		cin >> N;
		cin >> n1;
		for (int j = 1; j < N; j++) {
			n2 = n1;
			cin >> n1;
			temp = n1 - n2;
			if (temp > upD)
				upD = temp; //올라갈 때의 최대 높이 변화 갱신
			if (temp < downD)
				downD = temp; //내려갈 때의 최대 높이 변화 갱신
		}
		answer += "#" + to_string(i) + " " + to_string(upD) + " " + to_string(downD * -1) + "\n";
	}
	cout << answer;
	return 0;
}
