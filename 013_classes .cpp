//
// Created by Massimo Biancalani on 2019-09-24.
//
#include <string>

using namespace std;

class Student {
private:
    unsigned int age;
    unsigned int standard;
    string first_name;
    string last_name;
public:
    void set_age(unsigned int age)  {
        this->age = age;
    };
    void set_standard(unsigned int standard)  {
        this->standard = standard;
    };
    void set_first_name(string first_name)  {
        this->first_name = first_name;
    };
    void set_last_name(string last_name)  {
        this->last_name = last_name;
    };

    unsigned int get_age() const {
        return this->age;
    }

    unsigned int get_standard() const {
        return this->standard;
    }

    string get_first_name() const {
        return this->first_name;
    }

    string get_last_name() const {
        return this->last_name;
    }

    string to_string() const {
        return std::to_string(age) + "," + first_name + "," + last_name + "," + std::to_string(standard);
    }
};