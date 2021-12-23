#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    int N = right - left + 1; //1차원 배열 크기

    vector<int> answer(N);
    for (int i = 0; i < N; ++i, ++left) {
        int r = left / n; //행
        int c = left % n; //열
        answer[i] = (r < c ? c : r) + 1; //행과 열 값 중 더 큰 값 + 1을 넣음
    }

    return answer;
}
