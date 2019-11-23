#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);
	string temp1, temp2;
	for (int i = 0; i < n; i++) {
		temp1 = (bitset<16>(arr1[i]) | bitset<16>(arr2[i])).to_string(); //비트OR연산
		temp2 = "";
		for (int j = 16 - n; j < 16; j++) {
			if (temp1[j] == '1')
				temp2 += "#";
			else
				temp2 += " ";
		}
		answer[i] = temp2;
	}
	return answer;
}