#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    // = Exercise 1 = //
    bool ex1 = true;
    cout << "Exercise 1: "<<ex1 << endl;

    // = Exercise 2 = //
    char ex2 = '/';
    cout << "Exercise 2: " << ex2 << endl;
    
    // = Exercise 3 = //
    short ex3 = 40000;
    cout << "Exercise 3: " << ex3 << endl;

    // = Exercise 4 = //
    unsigned short ex4 = 40000;
    cout << "Exercise 4: " << ex4 << endl;

    // = Exercise 5 = //
    int ex5 = 40000;
    cout << "Exercise 5: " << ex5 << endl;

    // = Exercise 6 = //
    double pi = 3.14159265359;
    float ex6 = pi;
    cout << "Exercise 6: " << ex6 << endl;

    // = Exercise 7 = //
    char ex7[] = "I like coding!";
    cout << "Exercise 7: " << ex7 << endl;

    // = Exercise 8 = //
    string ex8 = "i like C++";
    cout << "Exercise 8: " << ex5 << endl;

    // = Exercise 9 = //
    vector<int> v = { 1,2,3,4 };
    int ex9 = 5;
    v.push_back(ex9);
    cout << "Exercise 9: before: ";
    for (int i : v) cout << i;
    v.pop_back();
    cout << '\t' << "after: ";
    for (int i : v) cout << i;

    // = Exercise 10 = //
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "\nExercise 10: " << q.front() << ':' << q.back();
    
}


