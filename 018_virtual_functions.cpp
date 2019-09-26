#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Person {
protected:
    string name;
    unsigned int age;
    unsigned int cur_id;
public:
    virtual void getdata() {};
    virtual void putdata() {};
};

class Professor: public Person {
    unsigned int publications;
    inline static unsigned int next_id = 1;
public:
    Professor() : Person() {
        cur_id = next_id++;
    }
    void getdata() {
        cin >> name >> age >> publications;
    }
    void putdata() {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

class StudentVirtual : public Person {
    unsigned int marks[6];
    inline static unsigned int next_id = 1;
public:
    StudentVirtual() : Person() {
        cur_id = next_id++;
    }
    void getdata() {
        cin >> name >> age;
        for (int i = 0; i < 6; ++i) {
            cin >> marks[i];
        }
    }
    void putdata() {
        unsigned int total = accumulate(begin(marks), end(marks), 0, [] (int a, int b){ return a + b;});
        cout << name << " " << age << " " << total << " " << cur_id << endl;
    }
};

int virtual_function_main() {

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new StudentVirtual; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}