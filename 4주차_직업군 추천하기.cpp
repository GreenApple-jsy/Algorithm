#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

#define CONTENTS 0
#define GAME 1
#define HARDWARE 2
#define PORTAL 3
#define SI 4

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    vector <unordered_map<string, int> > whole_table(5);
    for (int i = 0; i < table.size(); ++i) {
        istringstream ss(table[i]);
        string word; int score = 5;
        getline(ss, word, ' ');
        
        if (word == "CONTENTS") {
            while (getline(ss, word, ' ')) {
                whole_table[CONTENTS].insert({ word, score });
                --score;
            }
        }
        else if (word == "GAME") {
            while (getline(ss, word, ' ')) {
                whole_table[GAME].insert({ word, score });
                --score;
            }
        }
        else if (word == "HARDWARE") {
            while (getline(ss, word, ' ')) {
                whole_table[HARDWARE].insert({ word, score });
                --score;
            }
        }
        else if (word == "PORTAL") {
            while (getline(ss, word, ' ')) {
                whole_table[PORTAL].insert({ word, score });
                --score;
            }
        }
        else if (word == "SI") {
            while (getline(ss, word, ' ')) {
                whole_table[SI].insert({ word, score });
                --score;
            }
        }
    }
    vector <int> score(5, 0);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < languages.size(); ++j) {
            if (whole_table[i].find(languages[j]) != whole_table[i].end()) {
                score[i] += preference[j] * (*(whole_table[i].find(languages[j]))).second;
            }
        } 
    }
    string answer = "CONTENTS";
    int max_score = score[0];
    for (int i = 1; i < 5; ++i) {
        if (score[i] > max_score) {
            if (i == 1)
                answer = "GAME";
            else if (i == 2)
                answer = "HARDWARE";
            else if (i == 3)
                answer = "PORTAL";
            else if (i == 4)
                answer = "SI";
            max_score = score[i];
        }
    }
    return answer;
}
