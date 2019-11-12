#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	int s = timetable.size();
	vector <int> timetableN(s); //타임테이블을 분단위로 저장
	for (int i = 0; i < s; i++)
		timetableN[i] = 60 * atoi(timetable[i].substr(0, 2).c_str()) + atoi(timetable[i].substr(3, 2).c_str());
	sort(timetableN.begin(), timetableN.end());
	int time = 540;
	int p = 0;
	int c = 0;
	bool check = false;
	for (int i = 1; i <= n; i++, time += t) {
		c = 0;
		while ((p < s) && (timetableN[p] <= time) && (c < m)) {
			p++;
			c++;
		}
		if ((c < m) && (timetableN[p] > time) && (i == n))
			check = true;
	}
	time -= t;
	int con = timetableN[p - 1];
	if (con == time)
		con -= 1;
	else if ((check) || (timetableN.front() > time))
		con = time;
	else if (con < time) {
		if ((c < m) && (p == s))
			con = time;
		else if (c >= m)
			con -= 1;
	}
	if (con / 60 < 10) {
		if (con % 60 < 10)
			return "0" + to_string(con / 60) + ":0" + to_string(con % 60);
		else
			return "0" + to_string(con / 60) + ":" + to_string(con % 60);
	}
	else {
		if (con % 60 < 10)
			return to_string(con / 60) + ":0" + to_string(con % 60);
		else
			return to_string(con / 60) + ":" + to_string(con % 60);
	}
}
