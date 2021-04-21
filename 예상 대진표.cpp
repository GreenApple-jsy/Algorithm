#include <iostream>
#include <math.h>
using namespace std;

int get_nextN(int currentN) {
    if (currentN % 2 == 0)
        return currentN / 2;
    else
        return (currentN + 1) / 2;
}

int solution(int n, int a, int b)
{
    int answer = 1;
    //두 참가자의 번호 차이가 1이고, 더 높은 번호가 2의 배수여야 서로 붙을 수 있음 
    while (!(abs(a - b) == 1 && max(a,b) % 2 == 0)) {
        a = get_nextN(a);
        b = get_nextN(b);
        answer++;
    }
    return answer;
}
