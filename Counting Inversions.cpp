#include <iostream>
using namespace std;

long long m_count;
int numbers[1000001];
int copyN[1000001];

// Merge Sort 과정에서 수 교환 횟수를 카운트
void merge_sort(int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);

    int idx = left, l = left, r = mid + 1;

    while (l <= mid || r <= right) {
        if ((l <= mid && numbers[l] < numbers[r]) || r > right) {
            copyN[idx] = numbers[l];
            idx++; l++;
        }
        else {
            m_count += ((long long)mid - l + 1);
            copyN[idx] = numbers[r];
            idx++; r++;
        }
    }

    for (int i = left; i <= right; i++)
        numbers[i] = copyN[i];
}

int main() {
	int N;
    m_count = 0;
		cin >> N;
		for (int i = 0; i < N; ++i) 
			cin >> numbers[i];

		merge_sort(0, N - 1);

		cout << m_count << endl;
	return 0;
}
