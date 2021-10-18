#include <iostream>
using namespace std;
  
int main() {
    int L;
    int buildings[1000];
    for (int i = 1; i <= 10; ++i) {
        int sum = 0;
        cin >> L;
        for (int j = 0; j < L; ++j)
            cin >> buildings[j];
  
        for (int j = 2; j < L - 2; ++j) {
            int highest = max(buildings[j - 2], buildings[j - 1]);
            highest = max(highest, buildings[j + 1]);
            highest = max(highest, buildings[j + 2]);
            if (buildings[j] > highest)
                sum += buildings[j] - highest;
        }
        cout << "#" << i << " " << sum << endl;
    }
    return 0;
}
