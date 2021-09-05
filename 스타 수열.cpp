#include <string>
#include <vector>
using namespace std;

int solution(vector<int> a) {
    int result = 0;
    if (a.size() < 2)
        return 0;

    vector<int> a_count(a.size(), 0); // a[i]에 대해 집합이 몇개인지
    vector<int> a_prev(a.size(), -1); //짝 지은 수 기억

    for (int i = 0; i < a.size(); ++i) {
        int num = a[i];

        if (i != 0 && a[i - 1] != num && a_prev[a[i]] != i - 1) {
            ++a_count[a[i]];
            a_prev[a[i]] = i - 1;
        }
        else if (i + 1 != a.size() && a[i + 1] != num) {
            ++a_count[a[i]];
            a_prev[a[i]] = i + 1;
        }
    }
    
    for (int i = 0; i < a.size(); ++i)
        result = max(a_count[i], result);

    return 2 * result;
}
