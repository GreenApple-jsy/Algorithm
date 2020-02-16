#include <string>
#include <vector>
using namespace std;

string solution(string s) {
	int i = 0;
	while (i < s.length()) {
		while (s[i] == ' ')
			i++;
		s[i] = toupper(s[i]);
		do {
			i++;
			s[i] = tolower(s[i]);
		} while ((i < s.length()) && (s[i] != ' '));
	}
	return s;
}