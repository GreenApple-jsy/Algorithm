#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
	float i = 0; float u = 0; //������, ������
	vector <string> vstr1, vstr2;
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper); //�빮�� ��ȯ
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	for (int i = 0; i < str1.length() - 1; i++) {
		if (isalpha(str1[i]) && isalpha(str1[i + 1])) //���ĺ��� ��츸 ���ҷ� ���
			vstr1.push_back(str1.substr(i, 2));
	}
	for (int i = 0; i < str2.length() - 1; i++) {
		if (isalpha(str2[i]) && isalpha(str2[i + 1]))
			vstr2.push_back(str2.substr(i, 2));
	}
	if (vstr1.size() == 0 && vstr2.size() == 0) //�� �� �������� ���
		return 65536;
	sort(vstr1.begin(), vstr1.end()); //���������� ����
	sort(vstr2.begin(), vstr2.end());
	int m = 0; int n = 0; //�� ������ �� �ε���
	while (m < vstr1.size() && n < vstr2.size()) {
		if (vstr1[m] == vstr2[n]) { //������ & �����տ� �߰�
			i++; u++;
			m++; n++;
		}
		else if (vstr1[m] > vstr2[n]) { //�����տ� �߰�
			u++;
			n++;
		}
		else if (vstr1[m] < vstr2[n]) { //�����տ� �߰�
			u++;
			m++;
		}
	}
	u += vstr1.size() - m; //���� ���Ҹ� �����տ� ����
	u += vstr2.size() - n;
	return int(i / u * 65536);
}