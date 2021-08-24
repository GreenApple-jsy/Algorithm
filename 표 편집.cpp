#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int num;
    Node* prev;
    Node* next;
};

string solution(int n, int k, vector<string> cmd) {
    int current = k;
    stack <int> del_list; // 삭제 기록
    vector <bool> del_check(n, true); // 삭제 여부 확인용
    vector <Node *> table(n); // 양방향 연결리스트

    for (int i = 0; i < n; ++i)
        table[i] = new Node{ i, NULL, NULL };

    table[0]->next = table[1];
    table[n - 1]->prev = table[n - 2];

    for (int i = 1; i < n - 1; i++) {
        table[i]->next = table[i + 1];
        table[i]->prev = table[i - 1];
    }

    for (int i = 0; i < cmd.size(); ++i) {

        // 위로 이동
        if (cmd[i][0] == 'U') {
            int num = stoi(cmd[i].substr(2));
            for (int j = 0; j < num; ++j)
                current = table[current]->prev->num;
        }

        // 아래로 이동
        else if (cmd[i][0] == 'D') {
            int num = stoi(cmd[i].substr(2));
            for (int j = 0; j < num; ++j)
                current = table[current]->next->num;
        }

        // 선택 삭제
        else if (cmd[i][0] == 'C') {
            del_list.push(table[current]->num);
            del_check[table[current]->num] = false;

            if (table[current]->prev != NULL)
                table[current]->prev->next = table[current]->next;

            if (table[current]->next == NULL) {
                current = table[current]->prev->num;
            }
            else {
                table[current]->next->prev = table[current]->prev;
                current = table[current]->next->num;
            }
        }

        // 직전 삭제 복구
        else if (cmd[i][0] == 'Z') {
            int last_del = del_list.top();
            del_list.pop();
            if (table[last_del]->prev != NULL)
                table[last_del]->prev->next = table[last_del];
            if (table[last_del]->next != NULL)
                table[last_del]->next->prev = table[last_del];

            del_check[last_del] = true;
        }
    }

    string answer = "";
    for (int i = 0; i < del_check.size(); i++) {
        if (del_check[i] == true)
            answer += "O";
        else
            answer += "X";
    }

    return answer;
}
