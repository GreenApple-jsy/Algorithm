#include <string>
#include <vector>
using namespace std;

string solution(int n, int t, int m, int p) {
	vector <char> temp;
	string answer = "";
	int CurrentN = 0; //���ؾ� �ϴ� ��(10����)
	int CurrentTurn = 1; //���� ���° ���ΰ�
	temp.push_back('0');
	if (m == p)
		p = 0;
	while (CurrentTurn <= t * m) {
		int N = CurrentN;
		while (N > 0) {
			if (N % n >= 10)
				temp.push_back((char)(N % n + 55));
			else 
				temp.push_back((char)(N % n + 48));
			N /= n;
		}
		int s = temp.size();
		for (int i = 0; i < s; i++, CurrentTurn++) {
			if ((CurrentTurn % m == p) && (answer.length() < t)) //Ʃ�� ������ ���� ����
				answer += temp.back();
			temp.pop_back();
		}
		CurrentN++;
	}
	return answer;
}