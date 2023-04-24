#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    vector<int> a = {1, 2, 3, 4, 3 , 2, 1};
    unordered_map<int, int> map;
    int unique_element = 0;

    for (int i =0; i <= a.size(); i++){
        map[a[i]]++; // make index
    }
    for (int i = 0; i <= a.size(); i++){
        if (map[a[i]]<2){
            unique_element = map[a[i]];
        }
    }

}