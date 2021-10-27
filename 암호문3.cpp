#include <iostream>
using namespace std;

#define MAX 999999

// Double Linked List
struct ListNode {
    int data;
    ListNode* prev;
    ListNode* next;

    ListNode* myAlloc(int _data, ListNode* _prev, ListNode* _next) {
        data = _data;
        prev = _prev;
        next = _next;
        _next->prev = this;
        return this;
    }

} LinkedList[MAX];

ListNode head, tail; //리스트의 head, tail
int bufferCount;

// 초기화
void init() {
   bufferCount = 0;
   head.next = &tail;
}

// 해당 index번 째 node를 찾아서 리턴
ListNode* getNode(int _index) {
    ListNode* ptr = &head;
    for (int i = 1; i <= _index; ++i) {
        ptr = ptr->next;
        if (ptr == &tail)
            break;
    }
    return ptr;
}

// currentPtr 뒤에 node 삽입
ListNode* InsertNode(ListNode* currentPtr, int _data) {
    ListNode* temp = currentPtr->next;
    currentPtr->next = LinkedList[bufferCount++].myAlloc(_data, currentPtr, temp);
    return currentPtr->next;
}

// CurrentPtr 뒤부터 N개의 노드 삭제
void DeleteNode(ListNode* currentPtr, int N) {
    ListNode* ptr = currentPtr;
    for (int i = 0; i < N; ++i) {
        if (ptr->next != &tail)
            ptr = ptr->next;
    }
    currentPtr->next = ptr->next;
    ptr->next->prev = currentPtr;
}

// 리스트 맨 뒤에 노드 삽입
void AddNode(int N) {
    ListNode* node = LinkedList[bufferCount++].myAlloc(N, tail.prev, &tail);
    tail.prev->next = node;
    tail.prev = node;
}

int main() {
    int num, input;
    char c;
    
    for (int T = 1; T <= 10; ++T) {
        ListNode* ptr = &head;
        init();
        cin >> num;
        for (int i = 1; i <= num; ++i) {
            cin >> input;
            ptr->next = LinkedList[bufferCount++].myAlloc(input, ptr, ptr->next);
            ptr = ptr->next;
        }
        cin >> num;
        for (int i = 1; i <= num; ++i) {
            cin >> c;
            if (c == 'I') {
                int pos, n, m;
                cin >> pos;
                ptr = getNode(pos);
                cin >> n;
                for (int j = 0; j < n; ++j) {
                    cin >> m;
                    ptr = InsertNode(ptr, m);
                }
            }
            else if (c == 'D') {
                int pos, n;
                cin >> pos >> n;
                ptr = getNode(pos);
                DeleteNode(ptr, n);
            }
            else if (c == 'A') {
                int n, t;
                cin >> n;
                for (int j = 0; j < n; ++j) {
                    cin >> t;
                    AddNode(t);
                }
            }
        }
        cout << "#" << T;
        ptr = head.next;
        for (int i = 0; i < 10; ++i) {
            cout << " " << ptr->data;
            ptr = ptr->next;
        }
        cout << "\n";
    }
    return 0;
}
