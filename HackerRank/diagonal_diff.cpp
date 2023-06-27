#include <bits/stdc++.h>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int left=0;
    int right = 0;
    int j = arr.size()-1;
    for(int i=0;i!=arr.size();i++){
        left += arr[i][i];
        right += arr[i][j];
        j--;
        cout << right << endl;

    }
    
    return abs(left-right);
}

int main(){
    vector<vector<int>> arr {{1, 2, 3},{4,5,6},{9,8, 9}};
    int result = diagonalDifference(arr);
    cout << result;
}