#pragma once
#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student
{
public:
    int get_age() const { return age; }
    string get_first_name() const { return first_name; }
    string get_last_name() const { return last_name; }
    int get_standard() const { return standard; }

    void set_age(int a) { age = a; }
    void set_first_name(string fn) { first_name = fn; }
    void set_last_name(string ln) { last_name = ln; }
    void set_standard(int st) { standard = st; }
    string to_string() {
        stringstream ss;
        char p = ',';
        ss << age << p << first_name << p << last_name << p << standard;
        return ss.str();
    }


private:
    int age;
    string first_name;
    string last_name;
    int standard;

};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}