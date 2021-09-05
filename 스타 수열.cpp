#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector <int> g_a;
vector <vector <int> > all_subseq;

//부분 수열 만들기
void make_subseq(vector<int> temp, int index, int sub_size) {
    if (temp.size() >= sub_size) {
        all_subseq.push_back(temp);
        return;
    }

    if (index > g_a.size() - 1)
        return;

    vector <int> b = temp;

    make_subseq(b, index + 1, sub_size);
    b.push_back(g_a[index]);
    make_subseq(b, index + 1, sub_size);

    return;
}

//스타 수열인지 판별
bool is_star_sub(vector<int> v) {
    pair <int, int> a; pair <int, int> b;
    a.first = v[0]; b.first = v[1];
    a.second = 0; b.second = 0;
    bool one_num = false; //교집합 원소의 개수가 1인가
    int num; //교집합 원소
    int v1, v2;

    for (int i = 0; i < v.size() - 1; i += 2) {
        v1 = v[i], v2 = v[i + 1];

        if (v1 == v2)
            return false;

        if (one_num) {
            if (v1 != num && v2 != num)
                return false;
        }
        else {
            if (v1 == a.first)
                a.second++;
            else if (v1 == b.first)
                b.second++;

            if (v2 == a.first)
                a.second++;
            else if (v2 == b.first)
                b.second++;

            if (v1 != a.first && v1 != b.first && v2 != a.first && v2 != b.first)
                return false;

            if (a.second > b.second) {
                num = a.first;
                one_num = true;
            }

            else if (a.second < b.second) {
                num = b.first;
                one_num = true;
            }

        }
    }
    return true;
}

int solution(vector<int> a) {
    g_a = a;
    int length = a.size() % 2 == 0 ? a.size() : a.size() - 1;

    for (; length >= 2; length -= 2) {
        all_subseq.clear();
        make_subseq({}, 0, length);
        for (int i = 0; i < all_subseq.size(); i++) {
            if (is_star_sub(all_subseq[i]))
                return length;
        }
    }
    return 0;
}
