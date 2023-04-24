#include <vector>
#include <iostream>
#include <string>


using namespace std;

bool is_reverse(vector<int> a){
    if ((a[0] +a[1]) < (a[2]+a[3])){
        return true;
    }
}

int main(){
    vector<vector<int>> matrix = {{112,42,83, 119},{56, 125, 56, 49},{15, 78, 101,43},{62,98, 114, 108}};

    // columns
    cout  << is_reverse(matrix[0]);

}