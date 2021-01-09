#include <string>
#include <vector>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    int answer_song_play_time = 0;
    string answer_song_title = "(None)";

    for (int i = 0; i < musicinfos.size(); i++) {
        int start_time = ((((musicinfos[i][0] - '0') * 10) + (musicinfos[i][1] - '0')) * 60) + ((musicinfos[i][3] - '0') * 10) + (musicinfos[i][4] - '0');
        int end_time = ((((musicinfos[i][6] - '0') * 10) + (musicinfos[i][7] - '0')) * 60) + ((musicinfos[i][9] - '0') * 10) + (musicinfos[i][10] - '0');
        int play_time = end_time - start_time;
        string song_title = "", song_melody = "";
        for (int j = 12; j < musicinfos[i].length(); j++) {
            if (musicinfos[i][j] == ',') {
                song_melody = musicinfos[i].substr(j + 1); //악보 정보
                break;
            }
            else
                song_title += musicinfos[i][j]; //음악 제목
        }

        int melody_index = 0;
        string whole_melody;//전체 재생된 멜로디
        for (int j = 0; j < play_time; j++) {
            whole_melody += song_melody[melody_index];
            melody_index++;
            if (song_melody[melody_index] == '#')
            {
                whole_melody += song_melody[melody_index];
                melody_index++;
            }
            if (melody_index >= song_melody.length())
                melody_index = 0;
        }

        if (whole_melody.length() >= m.length()) {
            for (int j = 0; j <= whole_melody.length() - m.length(); j++) {
                if (m == whole_melody.substr(j, m.length())) {
                    if (!(j + m.length() < whole_melody.length() && whole_melody[j + m.length()] == '#')) { //멜로디 뒤에 #이 붙어있는지 확인
                        if (play_time > answer_song_play_time) { //재생시간이 더 큰 경우에만 저장한 곡 갱신
                            answer_song_title = song_title;
                            answer_song_play_time = play_time;
                            break;
                        }
                    }
                }
            }
        }
    }
   return answer_song_title;
}
