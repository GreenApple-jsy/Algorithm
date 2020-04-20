#include <string>
#include <vector>
#include <map>
using namespace std;

map<long, long> room_map; //배정된 방들의 맵 <배정된 방 번호, 또 다른 고객이 원할 경우 배정될 다음 방 번호>

long long findAvailableRoomN(long long num) { //배정 가능한 방 중 가장 번호가 작은 방 찾기
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
		if(room_map[roomN] == 0){ //아직 배정되지 않은 방인 경우
			answer.push_back(roomN);
			room_map[roomN] = findAvailableRoomN(roomN + 1);
		}
		else{ //이미 배정된 방인 경우
			otherRoomN = findAvailableRoomN(roomN);
			answer.push_back(otherRoomN);
			room_map[otherRoomN] = findAvailableRoomN(otherRoomN + 1);
		} 
	}
	return answer; 
}