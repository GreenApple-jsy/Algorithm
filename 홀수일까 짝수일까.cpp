#include<iostream>
#include<string>
using namespace std;

int main()
{
	int T;
	string in;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> in;
		if ((int)in.substr(in.size() - 1, in.size())[0] % 2 == 0)
			printf("#%d Even\n", i);
		else
			printf("#%d Odd\n", i);
	}
	return 0;
}