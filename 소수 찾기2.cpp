#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector <bool> numbers(n + 1, true); //소수 확인을 위한 벡터
    for (int i = 2; i <= n; i++) {
        if (numbers[i] == true) {
            answer++;
            for (int j = (2 * i); j <= n; j += i) //찾은 소수의 배수들은 다 목록에서 제외
                numbers[j] = false;
        }
    }
    return answer;
}
