#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int K;
        cin >> K;
        string word;
        vector <string> words;
        cin >> word;
        int wordSize = word.length();
        for (int i = 0; i < wordSize; i++)
            words.push_back(word.substr(i, wordSize - i));
        sort(words.begin(), words.end());

        if (K > wordSize)
            cout << "#" << i << " none\n";
        else
            cout << "#" << i << " " << words[K - 1] << "\n";
    }
    return 0;
}
