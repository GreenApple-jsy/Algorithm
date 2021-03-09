#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct separated_names
{
	string HEAD, ORIGINAL_NAME;
	int NUMBER;
};

bool cmp(separated_names a, separated_names b) {
	if (a.HEAD != b.HEAD) //HEAD가 다른 경우 HEAD 사전순 정렬
		return a.HEAD < b.HEAD;
	else if (a.NUMBER != b.NUMBER)
		return a.NUMBER < b.NUMBER;
	else //HEAD가 같은 경우 NUMBER 크기순 정렬
		return 0 < 1;
}

vector<string> solution(vector<string> files) {
	vector <separated_names> separated_names(files.size());
	for (int i = 0; i < files.size(); i++) {
		int j = 0;
		while (!isdigit(files[i][j])) j++;
		int k = j;
		while (isdigit(files[i][k])) {
			k++;
			if (k - j >= 5)
				break;
		}
		separated_names[i].ORIGINAL_NAME = files[i]; //기존 파일명 저장
		transform(files[i].begin(), files[i].begin() + j, files[i].begin(), ::toupper); //HEAD의 알파벳을 모두 대문자로 변환
		separated_names[i].HEAD = files[i].substr(0, j); //처음 숫자가 나오기 전까지의 string을 HEAD에 저장
		separated_names[i].NUMBER = stoi(files[i].substr(j, k - j)); //처음 나온 연속된 숫자(최대 5자리)를 NUMBER에 저장
	}

	stable_sort(separated_names.begin(), separated_names.end(), cmp); //안정 정렬

	vector <string> answer;
	for (int i = 0; i < separated_names.size(); i++)
		answer.push_back(separated_names[i].ORIGINAL_NAME);

	return answer;
}
