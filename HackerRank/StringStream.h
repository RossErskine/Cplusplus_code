#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss{ str };
    vector<int> temp;
    int i;
    char ch;
    while(ss >> i) {
        temp.push_back(i);
        ss >> ch;
    }
    return temp;
}


void runStringStream()
{
    string str;
    getline(cin, str);
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
}
