#include <string>
using namespace std;

int longest;
string word; int wordsize;

void oddlengthCheck(int position) { //Ȧ�� ������ �Ӹ�����̶� ���������� ���� ���ϱ�
	int count = 1;
	for (int i = 1; i <= wordsize; i++) {
		if ((position - i < 0) || (position + i >= wordsize))
			break;
		if (word[position - i] == word[position + i])
			count += 2;
		else
			break;
	}
	if (count > longest)
		longest = count;
}
void evenlengthCheck(int position) { //¦�� ������ �Ӹ�����̶� ���������� ���� ���ϱ�
	int count = 0;
	for (int i = 0; i < wordsize; i++) {
		if ((position - i < 0) || (position + i >= wordsize - 1))
			break;
		if (word[position - i] == word[position + i + 1])
			count += 2;
		else
			break;
	}
	if (count > longest)
		longest = count;
}

int solution(string s)
{
	longest = 1;
	word = s;
	wordsize = s.length();
	for (int i = 0; i < s.length(); i++) {
		oddlengthCheck(i);
		evenlengthCheck(i);
	}
	return longest;
}