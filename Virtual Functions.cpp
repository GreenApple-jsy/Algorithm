#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
public:
    virtual void getdata() {

    };
    virtual void putdata() {

    };

};

static int s_count = 1;
static int p_count = 1;

class Professor : public Person {
private:
    int publications;
    int cur_id;
    string name;
    int age;

public:
    void getdata() {
        cur_id = p_count++;
        cin >> name >> age >> publications;
    };

    void putdata(){
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    };
};

class Student : public Person {
private:
    int marks[6];
    int cur_id;
    string name;
    int age;

public:
    void getdata() {
        cur_id = s_count++;
        cin >> name >> age >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5];
    };

    void putdata() {
        cout << name << " " << age << " " << marks[0]+ marks[1]+ marks[2]+ marks[3]+ marks[4]+ marks[5] << " " << cur_id << endl;
    };
};

int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person* per[n];

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
