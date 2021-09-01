#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Rock {
    int location; //바위 위치(시작 지점으로부터 떨어진 위치)
    int dist; // 이전 바위와의 거리
    Rock* prev; //이전 바위
    Rock* next; //다음 바위
};

bool cmp(const Rock* a, const Rock* b) {
    if (a->dist == b->dist)
        return a->location < b->location;
    else
        return a->dist < b->dist;
}

int solution(int distance, vector<int> rocks, int n) {
    vector <Rock*> ordered_rocks; //바위 정보 리스트

    if (n == rocks.size() < 2)
        return distance;

    sort(rocks.begin(), rocks.end());

    Rock* cur; Rock* prev; Rock* next;
    prev = new Rock{ rocks.front(), rocks.front(), NULL, NULL };
    ordered_rocks.push_back(prev);

    for (int i = 1; i < rocks.size(); ++i) {
        cur = new Rock{ rocks[i], rocks[i] - rocks[i - 1], prev, NULL };
        prev->next = cur;
        prev = cur;
        ordered_rocks.push_back(cur);
    }
    cur = new Rock{ distance, distance - rocks.back(), prev, NULL };
    prev->next = cur;
    ordered_rocks.push_back(cur);

    //이전 바위와의 거리가 가장 작은 바위부터 차례대로 제거
    for (int i = 0; i < n; ++i) {
        sort(ordered_rocks.begin(), ordered_rocks.end(), cmp);

        int current_index = 0;
        cur = *(ordered_rocks.begin());
        prev = cur->prev;
        next = cur->next;

        //맨 앞에 있는 바위인 경우
        if (prev == NULL) {
            next->dist += cur->dist;
            next->prev = NULL;
        }
        //도착지점인 경우(바로 앞에 있는 바위 제거 필요)
        else if (next == NULL) {
            cur->dist += cur->prev->dist;
            cur->prev = cur->prev->prev;
            cur->prev->prev->next = cur;
            current_index++;
        }
        else {
            cur->next->dist += cur->dist;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
       
        ordered_rocks.erase(ordered_rocks.begin() + current_index);
    }
        
    sort(ordered_rocks.begin(), ordered_rocks.end(), cmp);
    return (*(ordered_rocks.begin()))->dist;
}
