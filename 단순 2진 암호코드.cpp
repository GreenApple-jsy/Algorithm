#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T, N, M;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N >> M;
		char line[100];
		char code[56];
		bool found_line = false;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> line[j];
				if (line[j] == '1' && !found_line)
					found_line = true;
			}
			if (found_line) {
				for (int k = M - 1; k >= 0; --k) {
					if (line[k] == '1') {
						copy(line + k - 55, line + k + 1, code);
						break;
					}
				}
			}
		}
		int code_sum[8];
		bool wrong_code = false;
		for (int i = 0; i < 8; ++i) {
			string code_string = { code[i * 7 + 1], code[i * 7 + 2], code[i * 7 + 3], code[i * 7 + 4], code[i * 7 + 5], code[i * 7 + 6] };
			if (code_string == "001101")
				code_sum[i] = 0;
			else if (code_string == "011001")
				code_sum[i] = 1;
			else if (code_string == "010011")
				code_sum[i] = 2;
			else if (code_string == "111101")
				code_sum[i] = 3;
			else if (code_string == "100011")
				code_sum[i] = 4;
			else if (code_string == "110001")
				code_sum[i] = 5;
			else if (code_string == "101111")
				code_sum[i] = 6;
			else if (code_string == "111011")
				code_sum[i] = 7;
			else if (code_string == "110111")
				code_sum[i] = 8;
			else if (code_string == "001011")
				code_sum[i] = 9;
			else
				wrong_code = true;
		}
		if (!wrong_code && ((code_sum[0] + code_sum[2] + code_sum[4] + code_sum[6]) * 3 + code_sum[1] + code_sum[3] + code_sum[5] + code_sum[7]) % 10 == 0)
			cout << "#" << tc << " " << code_sum[0] + code_sum[1] + code_sum[2] + code_sum[3] + code_sum[4] + code_sum[5] + code_sum[6] + code_sum[7] << endl;
		else
			cout << "#" << tc << " " << 0 << endl;

	}
	return 0;
}
