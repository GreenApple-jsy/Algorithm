#include <string>
using namespace std;

string solution(int a, int b) {
    string days[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int monthDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = 0;
    
    for (int i = 0; i < a - 1; i++)
        day += monthDays[i];
    
    day += b;
    
    return days[day % 7];
}
