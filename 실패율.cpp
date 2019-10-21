#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector <vector<double>> failure(N, vector<double>(2)); //실패율,문제번호 저장
	int people = stages.size(); //사용자 수
	int current_index = 0; 
	sort(stages.begin(), stages.end());
	for (int i = 1; i <= N; i++) {
		int count = 0;
		int understage = current_index; //해당 스테이지에 도달 못한 사람 수
		while ((current_index < stages.size()) && (stages[current_index] <= i)) {
			if (stages[current_index] == i) //현재 해당 스테이지인 사용자
				count++;
			current_index++;
		}
		if (people - understage == 0) //스테이지에 도달한 사용자가 없는 경우 실패율을 0으로 처리
			failure[i - 1][0] = 0;
		else
			failure[i - 1][0] = (double)count / (people - understage); //실패율 = 현재 해당 스테이지인 사용자 / (전체 사용자 수 - 해당 스테이지에 도달 못한 사람 수)
		failure[i - 1][1] = i;
	}
	sort(failure.begin(), failure.end());
	for (int i = failure.size() - 1; i >= 0; i--) { //실패율을 내림차순으로 정렬
		if ((i != 0) && (failure[i][0] == failure[i - 1][0])) { //같은 실패율일때 문제 오름차순 삽입
			int temp = i;
			while ((temp != 0) && (failure[temp][0] == failure[temp - 1][0]))
				temp--;
			for (int j = temp; j <= i; j++)
				answer.push_back(failure[j][1]);
			i = temp;
		}
		else 
			answer.push_back(failure[i][1]);
	}
	return answer;
}
