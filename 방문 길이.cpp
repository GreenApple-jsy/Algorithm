#include <string>
using namespace std;

int solution(string dirs)
{
	int x = 5; int y = 5; //���� ��ġ�� �迭 ���� (5,5)�� ����
	int count = 0;
	int check[11][11][11][11]; //�� �湮 ����(�� x��ǥ, �� y��ǥ, �� x��ǥ, �� y��ǥ)

	for (int i = 0; i < dirs.length(); i++) {
		if (dirs[i] == 'U') {
			if (y < 10) {
				if (check[x][y][x][y + 1] != 1) {
					check[x][y][x][y + 1] = 1; //�湮�� ������ üũ
					check[x][y + 1][x][y] = 1;
					count++;
				}
				y++;
			}
		}
		else if (dirs[i] == 'D') {
			if (y > 0) {
				if (check[x][y][x][y -1] != 1) {
					check[x][y][x][y - 1] = 1;
					check[x][y - 1][x][y] = 1;
					count++;
				}
				y--;
			}
		}
		else if (dirs[i] == 'L') {
			if (x > 0) {
				if (check[x][y][x - 1][y] != 1) {
					check[x][y][x - 1][y] = 1;
					check[x - 1][y][x][y] = 1;
					count++;
				}
				x--;
			}
		}
		else if (dirs[i] == 'R') {
			if (x < 10) {
				if (check[x][y][x + 1][y] != 1) {
					check[x][y][x + 1][y] = 1;
					check[x + 1][y][x][y] = 1;
					count++;
				}
				x++;
			}
		}
	}
	return count;
}