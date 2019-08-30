int solution(int n) {
	int answer = 0;
	int p = 1;
	int q = 1;
	if (n == 1)
		return 1;
	else {
		for (int i = 2; i <= n; i++) {
			answer = (p + q) % 10007;
			p = q;
			q = answer;
		}
	}
	return answer % 10007;
}