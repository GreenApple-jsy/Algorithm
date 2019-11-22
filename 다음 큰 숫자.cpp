#include <string>
#include <vector>
#include <bitset>
using namespace std;

int solution(int n) {
	int num = bitset<20>(n).count(); //10진수 -> 2진수 변환 후, 1의 개수 카운트 
	int i = n + 1;
	while (bitset<20>(i).count() != num)
		i++;
	return i;
}