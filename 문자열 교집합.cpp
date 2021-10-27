#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 100001
#define HASH_TABLE_SIZE (1 << 18)
#define MAX_KEY_LENGTH 51
#define DIV (HASH_TABLE_SIZE - 1)


struct Node {
	char key[MAX_KEY_LENGTH];
	Node* next;

	Node* alloc(char _key[], Node* _next) {
		strcpy(key, _key);
		next = _next;
		return this;
	}

	Node* getPrevNode(char _key[]) {
		Node* ptr = this;
		while (ptr->next) {
			if (strcmp(_key, ptr->next->key) == 0)
				break;
			
			ptr = ptr->next;
		}
		return ptr;
	}
};

int bCnt;
Node buf[MAXN];
Node HashTable[HASH_TABLE_SIZE];

void init() {
	bCnt = 0;
	for (int i = 0; i < HASH_TABLE_SIZE; ++i)
		HashTable[i].next = 0;
}

int getKey(char str[]) {
	unsigned long long key = 5381;

	for (int i = 0; str[i]; ++i)
		key = ((key << 5) + key) + (str[i] - 'a' + 1);

	return (int)(key & DIV);
}

bool find(char key[]) {
	Node* prev;
	int k = getKey(key);
	prev = HashTable[k].getPrevNode(key);
	return ((prev->next != nullptr) && (strcmp(prev->next->key, key) == 0));
}

void add(char key[]) {
	int k = getKey(key);
	HashTable[k].next = buf[bCnt++].alloc(key, HashTable[k].next);
}

int main() {
	int T, N, M, answer;
	char s[MAX_KEY_LENGTH];
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		init();
		answer = 0;
		cin >> N >> M;
		for (int i = 0; i < N; ++i) {
			scanf("%s", &s);
			add(s);
		}
		for (int i = 0; i < M; ++i) {
			cin >> s;
			if (find(s))
				answer++;
		}
		cout << "#" << tc << " " << answer << endl;
	}
	return 0;
}
