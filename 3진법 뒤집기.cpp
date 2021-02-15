#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    vector <int> num;
    int answer = 0;
    while (n > 0) {
        num.push_back(n % 3);
        n /= 3;
    }
    int numSize = num.size();
    for (int i = 0; i < numSize; i++)
        answer += pow(3, numSize - i - 1) * num[i];
    return answer;
}
