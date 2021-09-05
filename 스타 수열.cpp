#include <string>
#include <vector>
using namespace std;

vector <int> g_a;

//부분 수열 만들기
void make_subseq(vector<int> temp, int index, int sub_size) {
    if (temp.size() >= sub_size)
        return;

    if (index > g_a.size() - 1)
        return;
}

//스타 수열인지 판별
bool is_star_sub(vector<int> a) {


}

int solution(vector<int> a) {
    g_a = a;
    int length = a.size() % 2 == 0 ? a.size() : a.size() - 1;

    for (; length > 0; length -= 2) {
        vector <int> temp;
        make_subseq(temp, 0, length);
        if (is_star_sub(temp))
            return length;
    }
    return 0;
}
