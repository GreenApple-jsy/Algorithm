#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer = { 0,0 };
	vector<vector<string>> alphabet_words; //시작 알파벳으로 분류하여 지금까지 말한 단어 저장
	alphabet_words.reserve(36);
	alphabet_words[(int)words[0][0] - 97].push_back(words[0]);
	for (int i = 1; i < words.size(); i++) {
		if (words[i][0] != words[i - 1].back()) { //시작하는 글자가 전 단어 마지막 글자와 다름
			answer = { (i % n) + 1,(i / n) + 1 };
			return answer;
		}
		int alphabet = (int)words[i][0] - 97;
		for (int j = 0; j < alphabet_words[alphabet].size(); j++) {
			if (words[i] == alphabet_words[alphabet][j]) { //이미 말한 단어
				answer = { (i % n) + 1,(i / n) + 1 };
				return answer;
			}
		}
		alphabet_words[alphabet].push_back(words[i]);
	}
	return answer;
}