#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector <vector<int>> triangles(n);
    for (int i = 0; i < n; i++)
        triangles[i].resize(i + 1);
    
    int startRow = 0; // 반시계 채우기를 시작할 층
    int endRow = n - 1;
    int startCol = 0;
    int currentNum = 1;
    while (1) { //삼각형마다 반시계 방향으로 반복적으로 수 채우기

         //왼쪽 하단으로 내려가면서 채우기 ↙
        for (int i = startRow; i <= endRow; i++, currentNum++)
            triangles[i][startCol] = currentNum;

        // 아랫변 채우기 →
        for (int i = startCol + 1; i < n - startRow; i++, currentNum++) 
            triangles[endRow][i] = currentNum;

        //오른쪽 하단에서부터 올라가면서 채우기 ↖
        for (int i = endRow - 1; i > startRow; i--, currentNum++) 
            triangles[i][triangles[i].size() - startCol - 1] = currentNum;

        startRow += 2; // 다음 반시계 방향 채우기를 시작할 위치 갱신

        if (startRow >= endRow) //갱신한 startRow가 이미 채워진 Row와 겹치면 종료
            break;

        endRow -= 1;
        startCol += 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < triangles[i].size(); j++)
            answer.push_back(triangles[i][j]);
    }
    return answer;
}
