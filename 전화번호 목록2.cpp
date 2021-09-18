#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int char_to_int(char c) {
	return c - '0';
}

struct Trie {
	Trie* children[10];
	bool is_end = false;

	void insert(const char* num) {
		if (*num == '\0') {
			is_end = true;
		}
		else {
			int index = char_to_int(*num);
			if (children[index] == 0)
				children[index] = new Trie();
			children[index]->insert(num + 1);
		}
	}

	bool find(const char* key) {
		if (*key == '\0')
			return true;

		if (is_end)
			return false;

		int index = char_to_int(*key);
		return children[index]->find(key + 1);
	}
};

int main() {
	char phoneNum_list[10000][11];
	int T, N;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		
		Trie* trie = new Trie();
		cin >> N;
		for (int j = 0; j < N; ++j) {
			scanf("%s", &phoneNum_list[j]);
			trie->insert(phoneNum_list[j]);
		}

		bool is_ok = true;

		for (int j = 0; j < N; ++j) {
			if (trie->find(phoneNum_list[j]) == false) {
				is_ok = false;
				break;
			}
		}
		cout << (is_ok ? "YES" : "NO") << endl;
	}
	return 0;
}
