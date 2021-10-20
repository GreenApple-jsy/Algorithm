#include <iostream>
#include <string.h>
using namespace std;

int main() {
	string sentence, word;
	for (int i = 1; i <= 10; ++i) {
		int tc_num, count = 0, index = 0;
		cin >> tc_num >> word >> sentence;
		int word_length = word.length();
		while (index < sentence.length() - word_length + 1) {
			if (word == sentence.substr(index, word_length)) {
				count++;
				index += word_length;
			}
			else
				index++;
		}
		cout << "#" << i << " " << count << endl;
	}
}
