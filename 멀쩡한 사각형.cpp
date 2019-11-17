using namespace std;

long long solution(int w, int h)
{
	// ���� �������鼭 ��ġ�� �簢�� ������ ��� ������ ��Ģ���̴�
	// ����� ũ���  (w / �ִ� �����) x  (h / �ִ� �����)
	// �� ��� �ȿ��� (����� ���� ũ�� + ����� ���� ũ�� - 1) ����ŭ�� �簢�� ���� ���� ������
	int gcd;
	long long sum = (long long)w * (long long)h;
	
	for (int i = (w < h) ? w : h; i > 0; i--) {
		if ((w % i == 0) && (h % i == 0)) { //�ִ� ����� ���ϱ�
			gcd = i;
			break;
		}
	}
	return sum - gcd * ((w / gcd) + (h / gcd) - 1);
}