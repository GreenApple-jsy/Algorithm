#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N, sum = 0;
        cin >> N;
        vector <string> words;
        words.resize(3);
        for (int j = 0; j < 3; j++)
            cin >> words[j];
        for (int k = 0; k < N; k++) {
            if (words[0][k] == words[1][k]) {
                if (words[1][k] != words[2][k])
                    sum++;
            }
            else if (words[0][k] != words[1][k]) {
                if (words[0][k] == words[2][k])
                    sum++;
                else if (words[0][k] != words[2][k]) {
                    if (words[1][k] == words[2][k])
                        sum++;
                    else if (words[1][k] != words[2][k])
                        sum += 2;
                }
            }
        }
        cout << "#" << i << " " << sum << "\n";
    }
    return 0;
}
