#include <string>
#include <vector>
#include <bitset>
using namespace std;

int solution(int n) {
	int num = bitset<20>(n).count(); //10���� -> 2���� ��ȯ ��, 1�� ���� ī��Ʈ 
	int i = n + 1;
	while (bitset<20>(i).count() != num)
		i++;
	return i;
}