#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	for (int rl = 1; rl <= red; rl++) {
		if ((red % rl) == 0) {
			if (((2 * rl) + (2 * red / rl) + 4) == brown)
				return { (red / rl) + 2, rl + 2 };
		}
	}
}