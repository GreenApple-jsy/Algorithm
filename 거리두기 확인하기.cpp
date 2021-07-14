#include <string>
#include <vector>
using namespace std;

vector<vector<char>> seats;

bool check_p1(int x, int y) {
    if (seats[y][x - 2] == 'P' && seats[y][x - 1] != 'X')
        return false;  
    else
        return true;
}

bool check_p2(int x, int y) {
    if (seats[y - 1][x - 1] == 'P' && (seats[y][x - 1] != 'X' || seats[y - 1][x] != 'X'))
        return false;
    else
        return true;
}

bool check_p3(int x, int y) {
    if (seats[y][x - 1] == 'P')
        return false;
    else
        return true;
}

bool check_p4(int x, int y) {
    if (seats[y + 1][x - 1] == 'P' && (seats[y][x - 1] != 'X' || seats[y + 1][x] != 'X'))
        return false;
    else
        return true;
}

bool check_p5(int x, int y) {
    if (seats[y - 2][x] == 'P' && seats[y - 1][x] != 'X')
        return false;
    else
        return true;
}

bool check_p6(int x, int y) {
    if (seats[y - 1][x] == 'P')
        return false;
    else
        return true;
}

bool check_p7(int x, int y) {
    if (seats[y + 1][x] == 'P')
        return false;
    else
        return true;
}

bool check_p8(int x, int y) {
    if (seats[y + 2][x] == 'P' && seats[y + 1][x] != 'X')
        return false;
    else
        return true;
}

bool check_p9(int x, int y) {
    if (seats[y - 1][x + 1] == 'P' && (seats[y][x + 1] != 'X' || seats[y - 1][x] != 'X'))
        return false;
    else
        return true;
}

bool check_p10(int x, int y) {
    if (seats[y][x + 1] == 'P')
        return false;
    else
        return true;
}

bool check_p11(int x, int y) {
    if (seats[y + 1][x + 1] == 'P' && (seats[y][x + 1] != 'X' || seats[y + 1][x] != 'X'))
        return false;
    else
        return true;
}

bool check_p12(int x, int y) {
    if (seats[y][x + 2] == 'P' && seats[y][x + 1] != 'X')
        return false;
    else
        return true;
}

//자신을 기준으로 주변 12개의 자리에 대해 거리두기 준수 여부 확인
/*
      p5
   p2 p6 p9
p1 p3 나 p10 p12
   p4 p7 p11
      p8
*/
bool check_ok(int x, int y) {
    bool is_ok = true;

    if (seats[y][x] != 'P')
        return true;

    if (is_ok && x >= 2)
        is_ok = check_p1(x, y);

    if (x >= 1) {
        if (is_ok && y >= 1)
            is_ok = check_p2(x, y);
        if (is_ok)
            is_ok = check_p3(x, y);
        if (is_ok && y < 4)
            is_ok = check_p4(x, y);
    }

    if (is_ok && y >= 2)
        is_ok = check_p5(x, y);

    if (is_ok && y >= 1)
        is_ok = check_p6(x, y);

    if (is_ok && y < 4)
        is_ok = check_p7(x, y);

    if (is_ok && y < 3)
        is_ok = check_p8(x, y);

    if (x < 4) {
        if (is_ok && y >= 1)
            is_ok = check_p9(x, y);
        if (is_ok)
            is_ok = check_p10(x, y);
        if (is_ok && y < 4)
            is_ok = check_p11(x, y);
    }

    if (is_ok && x < 3)
        is_ok = check_p12(x, y);

    return is_ok;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    seats.resize(5);

    for (int i = 0; i < places.size(); i++) {
        int is_ok = 1;
        for (int j = 0; j < 5; j++) {
            seats[j].resize(5);
            for (int k = 0; k < 5; k++)
                seats[j][k] = places[i][j][k];
        }

        for (int j = 0; j < 5 && is_ok == 1; j++) {
            for (int k = 0; k < 5; k++) {
                if (check_ok(k, j) == false) {
                    is_ok = 0;
                    break;
                }
            }
        }
        answer.push_back(is_ok);
    }
    return answer;
}
