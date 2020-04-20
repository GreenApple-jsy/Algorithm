#include <string>
#include <vector>
#include <map>
using namespace std;

map<long, long> room_map; //������ ����� �� <������ �� ��ȣ, �� �ٸ� ���� ���� ��� ������ ���� �� ��ȣ>

long long findAvailableRoomN(long long num) { //���� ������ �� �� ���� ��ȣ�� ���� �� ã��
	if (room_map[num] == 0) {
		return num;
	}
	else {
		room_map[num] = findAvailableRoomN(room_map[num]);
		return room_map[num];
	}
}


vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	long long roomN;
	long long otherRoomN;

	for(int i = 0; i < room_number.size(); i++){
		roomN = room_number[i];
		if(room_map[roomN] == 0){ //���� �������� ���� ���� ���
			answer.push_back(roomN);
			room_map[roomN] = findAvailableRoomN(roomN + 1);
		}
		else{ //�̹� ������ ���� ���
			otherRoomN = findAvailableRoomN(roomN);
			answer.push_back(otherRoomN);
			room_map[otherRoomN] = findAvailableRoomN(otherRoomN + 1);
		} 
	}
	return answer; 
}