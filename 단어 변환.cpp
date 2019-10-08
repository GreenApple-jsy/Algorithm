#include <string>
#include <vector>

using namespace std;
int minCount;
string targetS;

bool diffcheck(string a, string b) { //문자 한 개만 다른지 체크
	int count = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i])
			count++;
	}
	if (count == 1)
		return true;
	else
		return false;
}

void change(int count, string currentS, vector<string>leftwords) {
	if (diffcheck(currentS, targetS)) {
		if (count < minCount)
			minCount = count;
		return;
	}
	for (int i = 0; i < leftwords.size(); i++) {
		if (diffcheck(currentS, leftwords[i])) {
			vector <string> Newleftwords = leftwords;
			Newleftwords.erase(Newleftwords.begin() + i);
			change(count + 1, leftwords[i], Newleftwords);
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	minCount = 51;
	targetS = target;
	for (int i = 0; i < words.size(); i++) {
		if (target == words[i]) {
			words.erase(words.begin() + i);
			break;
		}
		if (i == words.size() - 1)
			return 0;
	}
	change(0, begin, words);
	if (minCount == 51)
		return 0;
	else
		return minCount + 1;
}
