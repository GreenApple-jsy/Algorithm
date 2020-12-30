#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
pair<int, int> home;
pair<int, int> company;
vector <pair<int, int>> customers;
bool check_visit[10];
int minD;
 
int cal_dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
 
void dfs(int sumD, int x1, int y1, int visitNum, bool check_visit[]) {
    if (sumD > minD)
        return;
    if (visitNum == customers.size()) {
        int d = cal_dist(x1, y1, home.first, home.second);
        if (sumD + d < minD)
            minD = sumD + d;
        return;
    }
    for (int i = 0; i < customers.size(); i++) {
        if (check_visit[i] == false) {
            int x2 = customers[i].first; int y2 = customers[i].second;
            check_visit[i] = true;
            dfs(sumD + cal_dist(x1, y1, x2, y2), x2, y2, visitNum + 1, check_visit);
            check_visit[i] = false;
        }
    }
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T;
     
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N;
        minD = 987654321;
        cin >> N;
         
        customers.resize(N);
        memset(check_visit, false, sizeof(check_visit));
 
        cin >> company.first >> company.second >> home.first >> home.second;
 
        for (int j = 0; j < N; j++)
            cin >> customers[j].first >> customers[j].second;
 
        dfs(0, company.first, company.second, 0, check_visit);
 
        cout << "#" << i << " " << minD << "\n";
    }
    return 0;
}
