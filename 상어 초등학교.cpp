#include <iostream>
#include <vector>
using namespace std;

struct seat {
	int nearSpaceN;
	int studentN;
	vector <int> nearStudents;
};

vector <vector <seat> > board;
vector <vector<int> > student_info; //입력받는 정보(학생의 번호, 좋아하는 학생 번호)
vector <pair<int, int> > student_seat; //입력받은 학생 순서대로 앉은 자리 위치(x, y)

void find_seat(int num) {
	int board_size = board.size();
	int N = student_info.size();
	int f1 = student_info[num][1];
	int f2 = student_info[num][2];
	int f3 = student_info[num][3];
	int f4 = student_info[num][4];

	int max_spaceN = -1;
	pair <int, int> max_spaceSeat;

	int max_friendN = 0;
	int max_friendSeat_spaceN = 0;
	pair <int, int> max_friendSeat;

	pair <int, int> empty_seat;

	bool found_emptySeat = false;

	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size; j++) {
			if (board[i][j].studentN == 0) {

				if (!found_emptySeat) {
					empty_seat = { i, j };
					found_emptySeat = true;
				}

				if (board[i][j].nearSpaceN > max_spaceN) {
					max_spaceN = board[i][j].nearSpaceN;
					max_spaceSeat = { i, j };
				}

				int friend_count = 0;

				for (int k = 0; k < board[i][j].nearStudents.size(); k++) {
					int s = board[i][j].nearStudents[k];
					if ((s == f1) || (s == f2) || (s == f3) || (s == f4))
						friend_count++;
				}

				if (friend_count > max_friendN) {
					max_friendN = friend_count;
					max_friendSeat = { i, j };
					max_friendSeat_spaceN = board[i][j].nearSpaceN;
				}
				else if ((friend_count == max_friendN) && (board[i][j].nearSpaceN > max_friendSeat_spaceN)) {
					max_friendN = friend_count;
					max_friendSeat = { i, j };
					max_friendSeat_spaceN = board[i][j].nearSpaceN;
				}
			}
		}
	}
	pair <int, int> final_seat;

	if (max_friendN > 0)
		final_seat = max_friendSeat;
	else if (max_spaceN > 0)
		final_seat = max_spaceSeat;
	else
		final_seat = empty_seat;

	int x = final_seat.first, y = final_seat.second;
	int studentNum = student_info[num][0];
	board[x][y].studentN = studentNum;
	student_seat.push_back(final_seat);

	if (x > 0) {
		board[x - 1][y].nearSpaceN--;
		board[x - 1][y].nearStudents.push_back(studentNum);
	}

	if (x < board_size - 1) {
		board[x + 1][y].nearSpaceN--;
		board[x + 1][y].nearStudents.push_back(studentNum);
	}

	if (y > 0) {
		board[x][y - 1].nearSpaceN--;
		board[x][y - 1].nearStudents.push_back(studentNum);
	}

	if (y < board_size - 1) {
		board[x][y + 1].nearSpaceN--;
		board[x][y + 1].nearStudents.push_back(studentNum);
	}
}

int get_score(int num) {
	int f1 = student_info[num][1];
	int f2 = student_info[num][2];
	int f3 = student_info[num][3];
	int f4 = student_info[num][4];

	int x = student_seat[num].first, y = student_seat[num].second;

	int friendN = 0;

	for (int i = 0; i < board[x][y].nearStudents.size(); i++) {
		if ((board[x][y].nearStudents[i] == f1) ||
			(board[x][y].nearStudents[i] == f2) ||
			(board[x][y].nearStudents[i] == f3) ||
			(board[x][y].nearStudents[i] == f4))
			friendN++;
	}

	if (friendN == 0)
		return 0;
	else if (friendN == 1)
		return 1;
	else if (friendN == 2)
		return 10;
	else if (friendN == 3)
		return 100;
	else if (friendN == 4)
		return 1000;
}

int main() {
	int N;
	cin >> N;
	int studentN = N * N;
	student_info.resize(studentN);
	for (int i = 0; i < studentN; i++) {
		student_info[i].resize(5);
		for (int j = 0; j < 5; j++)
			cin >> student_info[i][j];
	}

	board.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			seat s;
			s.nearSpaceN = 4;
			s.studentN = 0;
			s.nearStudents = {};

			if ((i == 0 && j == 0) ||
				(i == 0 && j == N - 1) ||
				(i == N - 1) && (j == 0) ||
				(i == N - 1) && (j == N - 1))
				s.nearSpaceN = 2;
			else if ((i == 0) || (i == N - 1) || (j == 0) || (j == N - 1))
				s.nearSpaceN = 3;

			board[i].push_back(s);
		}
	}
	for (int i = 0; i < studentN; i++)
		find_seat(i);

	int score = 0;

	for (int i = 0; i < studentN; i++)
		score += get_score(i);

	cout << score;

	return 0;
}
