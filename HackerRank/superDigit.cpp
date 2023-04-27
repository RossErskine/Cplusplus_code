#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    if(n.size()==1){
        return (long)n[0]-48;
    }
    long tmp=0;
    for(long i=0;i<n.size();i++){
        tmp+=(((long)(n[i])-48)*k);
    }    
    n = to_string(tmp);
    cout <<  n << endl;
}
