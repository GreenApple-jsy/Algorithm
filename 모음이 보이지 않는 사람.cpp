#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<char>vowels = { 'a','e','i','o','u' };
	vector<string>words;
	int T, check;
	cin >> T;
	words.resize(T);
	for (int i = 0; i < T; i++)
		cin >> words[i];
	for (int i = 0; i < T; i++) {
		cout << "#" << i + 1 << " ";
		for (int j = 0; j < words[i].size(); j++) {
			for (check = 0; check < 5; check++) {
				if (words[i][j] == vowels[check])
					break;
			}
			if (check >= 5)
				cout << words[i][j];
		}
		cout << '\n';	
	}
	return 0;
}
