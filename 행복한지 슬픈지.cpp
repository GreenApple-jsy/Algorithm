#include <iostream>
#include <string>
using namespace std;

int main() {
	string sentence;
	getline(cin, sentence);
	string happy = ":-)", sad = ":-(", temp;
	int happyN = 0, sadN = 0;
	for (int i = 0; i < sentence.length() - 2; i++) {
		temp = sentence.substr(i, 3);
		if (temp == happy)
			happyN++;
		else if (temp == sad)
			sadN++;
	}
	if (happyN == 0 && sadN == 0)
		cout << "none";
	else if (happyN == sadN)
		cout << "unsure";
	else if (happyN > sadN)
		cout << "happy";
	else
		cout << "sad";
	return 0;
}
