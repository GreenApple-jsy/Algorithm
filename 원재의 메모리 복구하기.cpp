#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int answer = 0;
        bool current_val = false; //현재 바꾼 값
        string correct_value; //원래 메모리
        cin >> correct_value;
        for (int j = 0; j < correct_value.length(); j++) {
            if ((correct_value[j] - '0') != current_val) { //원래 메모리의 각 자리를 0,1 int로 변환하여 비교
                current_val = !current_val;
                answer++;
            }
        }
        cout << "#" << i << " " << answer << "\n";
    }
    return 0;
}
