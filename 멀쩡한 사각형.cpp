using namespace std;

long long solution(int w, int h)
{
	// 선이 지나가면서 겹치는 사각형 개수는 블록 단위로 규칙적이다
	// 블록의 크기는  (w / 최대 공약수) x  (h / 최대 공약수)
	// 한 블록 안에서 (블록의 가로 크기 + 블록의 세로 크기 - 1) 수만큼의 사각형 위로 선이 지나감
	int gcd;
	long long sum = (long long)w * (long long)h;
	
	for (int i = (w < h) ? w : h; i > 0; i--) {
		if ((w % i == 0) && (h % i == 0)) { //최대 공약수 구하기
			gcd = i;
			break;
		}
	}
	return sum - gcd * ((w / gcd) + (h / gcd) - 1);
}