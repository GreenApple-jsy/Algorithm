#include <string>
using namespace std;

int solution(string dirs)
{
	int x = 5; int y = 5; //시작 위치는 배열 기준 (5,5)로 지정
	int count = 0;
	int check[11][11][11][11]; //길 방문 여부(전 x좌표, 전 y좌표, 후 x좌표, 후 y좌표)

	for (int i = 0; i < dirs.length(); i++) {
		if (dirs[i] == 'U') {
			if (y < 10) {
				if (check[x][y][x][y + 1] != 1) {
					check[x][y][x][y + 1] = 1; //방문한 것으로 체크
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