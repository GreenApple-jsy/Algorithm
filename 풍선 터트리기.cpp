#include <vector>
using namespace std;

int solution(vector<int> a) {
    if (a.size() < 3)
        return a.size();
    vector <int> right_min = a;

    //오른쪽 끝에서부터 각 자리까지의 최소값을 저장
    for (int i = right_min.size() - 2; i > 0; i--)
        right_min[i] = min(right_min[i], right_min[i + 1]);

    int left_min = a.front();
    int answer = 2; //양 끝은 무조건 남을 수 있음

    //왼쪽부터 차례대로 최후까지 남을 수 있는지 확인
    for (int i = 1; i < a.size() - 1; i++) {
        //마지막 남은 양 옆의 풍선이 모두 작은 경우 최후까지 남을 수 없음
        if (!(a[i] > left_min && a[i] > right_min[i + 1]))
            answer++;

        left_min = min(left_min, a[i]);
    }
    return answer;
}
