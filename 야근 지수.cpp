#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;
	int size = works.size();
	int index = size - 1;
	sort(works.begin(), works.end()); //�۾������� �������� ��Ʈ
	while (n > 0) {
		n--;
		if (works[index] > 0)
			works[index]--;
		if (index == 0) {
			index = size - 1;
		}
		else { //���� ū �۾����� ���� �߱� Ÿ������ ����
			if (works[index] < works[index - 1])  
				index--;
			else
				index = size - 1;
		}
	}
	for (int i = 0; i < size; i++)
		answer += pow(works[i], 2);
	return answer;
}