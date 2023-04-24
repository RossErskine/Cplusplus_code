#include <vector>
#include <iostream>

vector<int> rotLeft(vector<int> a, int d) {
    vector<int> result;
    for (int i = d; i != a.size(); i++) {
        result.push_back(a[i]);
    }
    for (int i = 0; i != d ; i++) {
        result.push_back(a[i]);
    }
    return result;

}

int hourglassSum(vector<vector<int>> arr) {
    vector<vector<int>> hourGlass = { {1, 1, 1},{0,1,0},{1, 1, 1} };
    vector<int> sums;
    int highSum = -70;
    for (int i = 0; i != arr.size()-2; i++) {
        for (int j = 0; j != arr[i].size()-2; j++) {
            int sum = 0;
            for (int k = 0; k != hourGlass.size(); k++) {
               
                for (int l = 0;l != hourGlass[k].size(); l++) {
                    if (hourGlass[k][l] == 1) {
                        sum += arr[k+i][l+j];
                    }

                }
           }
            std::cout << sum << '\t';
            sums.push_back(sum);
        }
    }
    for (int i = 0; i != sums.size(); i++) {
        if (sums[i] > highSum) highSum = sums[i];
    }
    return highSum;
}

long repeatedString(string s, long n) {
    long freq =0, rc =0;
    int rem = n % s.length();
    for (int i = 0; i != s.length(); i++) {
        if (s[i] == 'a') {
            freq++;
            if (i < rem) rc++;
        }
    }
    return  n / s.length() * freq + rc;
}

int jumpingOnClouds(vector<int> c) {
    int leastJumps = 0;
    for (int i = 0; i < c.size() -1; i++) {
        if (c[i] != 1) {
            i++;
        }
        leastJumps++;
    }
    return leastJumps;
}

int countingValleys(int steps, string path) {
    int valleys = 0, seaLevel = 0;
    bool traversed = false;
    for (char ch : path){
        switch (ch)
        {
        case 'U':
            seaLevel++;
            if (seaLevel == 0 && traversed == true) {
                valleys++;
                traversed = false;
            }

            break;
        case 'D':
            seaLevel--;
            traversed = true;
            break;
        default:
            std::cout << " Not the instruction we were looking for!";
            break;
        }
    }
    return valleys;
}

void print_ar(std::vector<int> ar)
{
    for (int i = 0; i != ar.size(); i++)
    {
        std::cout << ar[i] << '\t';
    }
    std::cout << '\n';
}
int sockMerchant(int n, std::vector<int> ar)
{
    int count = 0;
    for (int i = 0; i != n; i++){
        for (int j = 0; j != ar.size(); j++) {
            if (ar[i] != 0 && i != j) {
                if (ar[i] == ar[j]) {
                    count++;
                    ar[i] = 0;
                    ar[j] = 0;
                }
            }
            print_ar(ar);
        }
    }
    return count;
}

void runInterview_prep()
{
	/*std::vector<int> ar = { 10, 20, 20, 10, 10, 30, 50, 10 ,20 };
    if (sockMerchant(ar.size(), ar) == 3) { std::cout << "Correct"; }
    else std::cout << "Wrong";*/

    /*int steps = 8;
    string path = "UDDDUDUU";
    std::cout << "valleys: " << countingValleys(steps, path);*/

    /*
    std::vector<int> clouds = { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 ,1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0 };
    std:cout << "Game won in " << jumpingOnClouds(clouds) << " jumps";*/
    /*
    string s = "ababa";
    long n = 100;
    std::cout << "Frequency of 'a' =  " << repeatedString(s, n);*/

    /*vector<vector<int>> arr{ {1,1,1,0,0,0},{0,1,0,0,0,0},{1,1,1,0,0,0},{0,0,2,4,4,0},{0,0,0,2,0,0},{0,0,1,2,4,0} };
    vector<vector<int>> arr2{ {-1, -1, 0, -9, -2, -2},{-2, -1, -6, -8, -2, -5,},{-1, -1, -1, -2, -3, -4},{-1, -9, -2, -4, -4, -5,},{-7, -3, -3, -2, -9, -9,},{-1, -3, -1, -2, -4, -5 } };
    std::cout << "Highest sum is: " << hourglassSum(arr2);*/

    vector<int> a = { 1,2,3,4,5 };
    int d = 4;
    vector<int> result = rotLeft(a, d);
    for (int i : result) {
        std::cout << i << '\t';
    }
}