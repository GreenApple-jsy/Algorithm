#include <string>
#include <vector>
using namespace std;

int distance(int &pos, int &target) {
    int sum = 0;
    int p = pos; int t = target;
    if (p == 0) p = 11;
    if (t == 0) t = 11;
    if (p > t + 1) { //손가락 위치가 더 아래 라인인 경우 위로 이동
        while (p > t + 1) {
            sum++;
            p -= 3;
        }
    }

    if (p < t - 1) { //손가락 위치가 더 위 라인인 경우 아래로 이동
        while (p < t - 1) {
            sum++;
            p += 3;
        }
    }

    sum += abs(p - t);
    return sum;
}



string solution(vector<int> numbers, string hand) {
    string answer = "";
    bool isLeft = (hand == "left") ? true : false;
    int left_pos = 10, right_pos = 12;

    for (int i = 0; i < numbers.size(); i++) {
        if ((numbers[i] == 1) || (numbers[i] == 4) || (numbers[i] == 7)) {
            answer += "L";
            left_pos = numbers[i];
        }
        else if ((numbers[i] == 3) || (numbers[i] == 6) || (numbers[i] == 9)) {
            answer += "R";
            right_pos = numbers[i];
        }
        else {
            if (distance(left_pos, numbers[i]) < distance(right_pos, numbers[i])) {
                answer += "L";
                left_pos = numbers[i];
            }
            else if (distance(left_pos, numbers[i]) > distance(right_pos, numbers[i])) {
                answer += "R";
                right_pos = numbers[i];
            }
            else { //두 손가락의 거리가 같은 경우
                if (isLeft) {
                    answer += "L";
                    left_pos = numbers[i];
                }
                else {
                    answer += "R";
                    right_pos = numbers[i];
                }
            }
        }
    }
    return answer;
}
