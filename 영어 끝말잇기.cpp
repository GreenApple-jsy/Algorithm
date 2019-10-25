#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer = { 0,0 };
	vector<vector<string>> alphabet_words; //���� ���ĺ����� �з��Ͽ� ���ݱ��� ���� �ܾ� ����
	alphabet_words.reserve(36);
	alphabet_words[(int)words[0][0] - 97].push_back(words[0]);
	for (int i = 1; i < words.size(); i++) {
		if (words[i][0] != words[i - 1].back()) { //�����ϴ� ���ڰ� �� �ܾ� ������ ���ڿ� �ٸ�
			answer = { (i % n) + 1,(i / n) + 1 };
			return answer;
		}
		int alphabet = (int)words[i][0] - 97;
		for (int j = 0; j < alphabet_words[alphabet].size(); j++) {
			if (words[i] == alphabet_words[alphabet][j]) { //�̹� ���� �ܾ�
				answer = { (i % n) + 1,(i / n) + 1 };
				return answer;
			}
		}
		alphabet_words[alphabet].push_back(words[i]);
	}
	return answer;
}