#include <vector>
using namespace std;

vector<vector<int>> g_picture;
int gM, gN;

int sizef(int h, int w, int color) {
	g_picture[h][w] = 0;
	int size = 1;
	if (w > 0 && color == g_picture[h][w - 1]) { //왼쪽
		g_picture[h][w] = 0;
		size += sizef(h, w - 1, color);
	}

	if (h > 0 && color == g_picture[h - 1][w]) { //위
		g_picture[h][w] = 0;
		size += sizef(h - 1, w, color);
	}

	if (w < gN - 1 && color == g_picture[h][w + 1]) { //오른쪽
		g_picture[h][w] = 0;
		size += sizef(h, w + 1, color);
	}

	if (h < gM - 1 && color == g_picture[h + 1][w]) { //아래
		g_picture[h][w] = 0;
		size += sizef(h + 1, w, color);
	}
	return size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	int size = 0;
	g_picture = picture;
	gM = m; gN = n;
	vector<int> answer(2);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (g_picture[i][j] != 0) {
				size = sizef(i, j, g_picture[i][j]);
				number_of_area++;
				if (max_size_of_one_area < size)
					max_size_of_one_area = size;
			}
		}
	}
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}