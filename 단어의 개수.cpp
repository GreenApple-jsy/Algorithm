#include <iostream>
#include <vector>
using namespace std;

int main() {
	int WordCount = 0;
	int start = 0, end;
	char c;
	vector <char> vc;
	while (true) {
		cin.get(c);
		if (c == '\n')
			break;
		else
			vc.push_back(c);
	}
	for (start = 0; start < vc.size(); start++) {
		if (vc[start] != ' ')
			break;
	}
	if (start == vc.size()) {
		cout << '0';
		return 0;
	}
	end = vc.size() - 1;
	while (vc[end] == ' ')
		end--;
	for (int i = start; i <= end; i++) {
		if (vc[i] == ' ')
			WordCount++;
	}
	cout << WordCount + 1;
}