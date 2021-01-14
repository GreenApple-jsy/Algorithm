#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int sum;

void find_word_set(int index, string alphabet, vector <string> words) {
	string temp = alphabet; // 알파벳 포함 정보를 담는 string(알파벳의 개수 = 26자리)

	//포함된 알파벳 자리에 1을 표시해줌
	for (int i = 0; i < words[index].length(); i++)
		temp[(int)words[index][i] - (int)'a'] = '1'; 

	// 모든 알파벳이 포함되어있다면
	// 남은 단어로 만들 수 있는 조합의 수 만큼 더해주고 재귀 종료
	if (temp == "11111111111111111111111111") { 
		sum += pow(2, words.size() - index - 1);
		return;
	}

	//재귀 호출
	for (int i = index + 1; i < words.size(); i++) 
		find_word_set(i, temp, words);
	return;	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		sum = 0;
		cin >> N;
		vector <string> words(N);
		for (int j = 0; j < N; j++)
			cin >> words[j];
		for (int j = 0; j < N; j++)
			find_word_set(j, {}, words); //만들 수 있는 조합을 재귀적으로 구함
		cout << "#" << i << " " << sum << "\n";
	}
	return 0;
}
