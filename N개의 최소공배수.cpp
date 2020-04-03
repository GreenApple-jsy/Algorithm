#include <string>
#include <vector>
using namespace std;

int FindLCM(int a, int b) { //최소 공배수 구하기
	int smallN = a < b ? a : b;
	int LCM = smallN;
	while (((LCM % a) != 0) || ((LCM % b) != 0))
		LCM += smallN;
	return LCM;
}

int solution(vector<int> arr) {
	for (int i = 0; i < arr.size() - 1; i++) 
		arr[i + 1] = FindLCM(arr[i], arr[i + 1]); //arr에서 순서대로 두 수를 짝지어 최소 공배수를 구함
	return arr.back();
}