#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector <int> c;
	vector<int> answer;
	int m = 0;
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i][0] == 'I')//�� �ֱ�
			c.push_back(atoi(operations[i].substr(2, operations[i].length()).c_str()));
		else if (c.size() != 0){
			if (operations[i][2] == '-')//�ּҰ� ã��
				m = *min_element(c.begin(), c.end());
			else //�ִ밪 ã��
				m = *max_element(c.begin(), c.end());
			for (int j = 0; j < c.size(); j++) { //����
				if (c[j] == m)
					c.erase(c.begin() + j);
			}
		}
	}


	return answer;
}