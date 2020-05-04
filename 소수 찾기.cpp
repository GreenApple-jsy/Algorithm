#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool IsPrimeN(int num) { //소수 판정 함수
	if (num <= 1)
		return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int solution(string numbers) {
	vector <int> primeNumbers; //찾은 소수 모음
	vector <bool> index; //조합을 만들기 위한 인덱스
	vector<int>::iterator iter;
	string temp;

	index.resize(numbers.length());
	sort(numbers.begin(), numbers.end());

	do { //numbers 순열 찾기
		for (int k = 1; k <= numbers.length(); k++) {
			for (int j = 0; j < k; j++) //앞에서부터만 k개만큼만 true 저장
				index[j] = true;
			for (int j = k; j < numbers.length(); j++) //나머지는 false 저장
				index[j] = false;
			do { //index의 순열을 이용하여 중복없이 numbers에서 k길이 조합 만들기
				temp = "";
				for (int j = 0; j < numbers.length(); j++) {
					if (index[j] == 1)
						temp += numbers[j];
				}
				if (IsPrimeN(atoi(temp.c_str()))) { //소수인 경우
					iter = find(primeNumbers.begin(), primeNumbers.end(), atoi(temp.c_str()));
					if (iter == primeNumbers.end()) //중복이 아닌 소수인 경우 저장
						primeNumbers.push_back(atoi(temp.c_str()));
				}
			} while (next_permutation(index.begin(), index.end()));
		}
	} while (next_permutation(numbers.begin(), numbers.end()));
	return primeNumbers.size();
}
