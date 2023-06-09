#include <vector>
#include <array>
#include <iostream>
#include <Windows.h>
#include "Binary_search.h"

using namespace std;
LONGLONG startTime = 0, endTime = 0, m_freqCount = 0;
void create_test1(vector<int>& vec, int vecSize)
{
    for (int i = 1; i <= vecSize; i++)
    {
        vec.push_back(i);
    }
}
template <size_t t>
void create_test2(array<int, t>& std_arr)
{
    for (int i = 1; i <= t; i++)
    {
        std_arr[i] = i++;
    }
}
void clearTime()
{
    startTime = 0;
    endTime = 0;
    m_freqCount = 0;
}

   

int main()
{
   
    
   
    Binary_search<int> bs;


    //=============creat vectors========//
    vector<int> vec10;
    vector<int> vec100;
    vector<int> vec1000;
    create_test1(vec10, 10);
    create_test1(vec100, 100);
    create_test1(vec1000, 1000);
    //===============create std array========//
    array<int, 10> sArrTen;
    array<int, 100> sArrHun;
    array<int, 1000> sArrThou;
    create_test2(sArrTen);
    create_test2(sArrHun);
    create_test2(sArrThou);
    //=============create C style array=========//
    int arrTen[10];
    for (int i = 0; i <= 9; i++)
    {
        arrTen[i] = i;
        
    }
    
    int arrHun[100];
    for (int j = 1; j <= 99; j++)
    {
        arrHun[j] = j++;
    }

    int arrThou[1000];
    for (int k = 1; k <= 999; k++)
    {
        arrThou[k] = k++;
    }

    //=====targets====//
    int x = 7;
    int y = 77;
    int z = 777;
   
    //=================================vector test=============================================//
    cout << "vector search: 10 elements" << endl;
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
    int resultVten = bs.binarySearch_vec(vec10, 0, vec10.size() - 1, x);//return result and index
    (resultVten == -1) ? cout << "Element was not found "
        : cout << "Element found at index: " << resultVten << endl;
    cout << "Iterations: " << bs.GetIteration() << endl;
    bs.clearIteretions();
    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
    cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
    clearTime();

    cout << "vector search: 100 elements" << endl;
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
    int resultVhun = bs.binarySearch_vec(vec100, 0, vec100.size() - 1, y);//return result and index
    (resultVhun == -1) ? cout << "Element was not found "
        : cout << "Element found at index: " << resultVhun << endl;
    cout << "Iterations: " << bs.GetIteration() << endl;
    bs.clearIteretions();
    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
    cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
    clearTime();

    cout << "vector search: 1000 elements" << endl;
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
    int resultVthou = bs.binarySearch_vec(vec1000, 0, vec1000.size() - 1, z);//return result and index
    (resultVthou == -1) ? cout << "Element was not found "
        : cout << "Element found at index: " << resultVthou << endl;
    cout << "Iterations: " << bs.GetIteration() << endl;
    bs.clearIteretions();
    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
    cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
    clearTime();
    //===========================std array=========================================//
    cout << "std array search: 10 elements" << endl;
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
    int resultSATen = bs.binarySearch_std_arr(sArrTen, 0, 10 - 1, x);//return result and index
    (resultSATen == -1) ? cout << "Element was not found "
        : cout << "Element found at index: " << resultSATen << endl;
    cout << "Iterations: " << bs.GetIteration() << endl;
    bs.clearIteretions();
    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
    cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
    clearTime();

    cout << "std array search: 100 elements" << endl;
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
    int resultSAHun = bs.binarySearch_std_arr(sArrHun, 0, 100 - 1, x);//return result and index
    (resultSAHun == -1) ? cout << "Element was not found "
        : cout << "Element found at index: " << resultSAHun << endl;
    cout << "Iterations: " << bs.GetIteration() << endl;
    bs.clearIteretions();
    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
    cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
    clearTime();

    cout << "std array search: 1000 elements" << endl;
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
    int resultSAThou = bs.binarySearch_std_arr(sArrThou, 0, 1000 - 1, x);//return result and index
    (resultSAThou == -1) ? cout << "Element was not found "
        : cout << "Element found at index: " << resultSAThou << endl;
    cout << "Iterations: " << bs.GetIteration() << endl;
    bs.clearIteretions();
    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
    cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
    clearTime();

    //==================================c style array test=============================//
    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
    cout << " C style array search: 10 elements" << endl;
    //int numTen = sizeof(arrTen) / sizeof(arrTen[0]);
    int resultTen = bs.binarySearch_C_arr(arrTen, 0 , 10 -1, x);//return result and index
    (resultTen == -1) ? cout << "Element was not found "
        : cout << "Element found at index: " << resultTen << endl;
    cout << "Iterations: " << bs.GetIteration() << endl;
    bs.clearIteretions();
    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
    cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
    clearTime();

    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
    cout << " C style array search: 100 elements" << endl;
    int numHun = sizeof(arrHun) / sizeof(arrHun[0]);
    int resultHun = bs.binarySearch_C_arr(arrHun, 0, numHun - 1, y);//return result and index
    (resultHun == -1) ? cout << "Element was not found "
        : cout << "Element found at index: " << resultHun << endl;
    cout << "Iterations: " << bs.GetIteration() << endl;
    bs.clearIteretions();
    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
    cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
    clearTime();

    QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
    cout << " C style array search: 1000 elements" << endl;
    int numThou = sizeof(arrThou) / sizeof(arrThou[0]);
    int resultThou = bs.binarySearch_C_arr(arrThou, 0, numThou - 1, z);//return result and index
    (resultThou == -1) ? cout << "Element was not found "
        : cout << "Element found at index: " << resultThou << endl;
    cout << "Iterations: " << bs.GetIteration() << endl;
    bs.clearIteretions();
    QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
    cout << " time taken: " << endTime - startTime << "ms" << endl << endl;

}



