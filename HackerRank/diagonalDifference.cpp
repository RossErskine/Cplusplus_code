#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{9,8,9}};


    int left=0;
    int right =0;
    for(unsigned int i =0; i != matrix.size();i++){
        left += matrix[i][i];
        
    }
    int j = matrix.size()-1;
    for (unsigned int i = 0; i != matrix.size(); i++){
            right += matrix[i][j];
            --j;
            cout << right << endl;
        
    }
    int diff = left - right;
    int absolute = abs(diff);
    cout << absolute << endl;
}