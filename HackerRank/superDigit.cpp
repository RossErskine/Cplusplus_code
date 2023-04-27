#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string n = "9875";
    int res = 0;
    for (char ch : n){
        
        res += (int)ch ;

    }
    cout << res << endl;
}