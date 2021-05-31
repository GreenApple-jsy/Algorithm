#include <string>
#include <vector>
using namespace std;

int findDivisorN(int num) {
    int divisorN = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0)
            divisorN++;
    }
    return divisorN;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++) {
        if (findDivisorN(i) % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    return answer;
}
