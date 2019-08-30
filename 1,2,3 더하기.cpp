#include <iostream>
#include <string>
using namespace std;

int c;
void func(int number) {
	if (number == 1)
		c++;
	else if (number == 2)
		c += 2;
	else if (number == 3)
		c += 4;
	else if (number == 4)
		c += 7;
	else {
		func(number - 3);
		func(number - 2);
		func(number - 1);
	}
}

int main() {
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		c = 0;
		cin >> n;
		func(n);
		cout << c << endl;
	}
}