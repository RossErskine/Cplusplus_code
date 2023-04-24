#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    vector<int> arr = {1,1,3,2,1};
    vector<int> result(4);

    for(int i = 0; i!= arr.size(); i++){
        result[arr[i]] +=1;
    }
    for(int i : result){
        cout << i << endl;
    }

}