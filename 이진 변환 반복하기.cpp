#include <string>
#include <vector>
using namespace std;

int run_count;
int zero_count;

string delete_zero(string s) {
	int zero_count_temp = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0')
			zero_count_temp++;
	}
	zero_count += zero_count_temp;
	string return_string(s.length() - zero_count_temp, '1');
	return return_string;
}

string length_to_binary(string s) {
	int i = s.length();
	string return_string = "";
	while (true) {
		return_string = to_string(i % 2) + return_string;
		i /= 2;
		if (i <= 1) {
			if (i == 1)
				return_string = to_string(i) + return_string;
			break;
		}
	}
	return return_string;
}

vector<int> solution(string s) {
	run_count = 0;
	zero_count = 0;
	while (s != "1") {
		s = delete_zero(s);
		s = length_to_binary(s);
		run_count++;
	}
	return { run_count, zero_count };
}
