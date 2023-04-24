#pragma once
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <Windows.h>
//#include <iostream>

using namespace std;

class Test_Vectors
{
private:
	//========Temp vectors for test=======//
	vector<int> temp10; 
	vector<int> temp50;
	vector<int> temp100; 
	vector<int> temp250;
	vector<int> temp500;
	vector<int> temp750;
	vector<int> temp1000; 
	//=========vectors for merging=======//
	vector<int> merg1_10;
	vector<int> merg2_10;
	vector<int> merg1_50;
	vector<int> merg2_50;
	vector<int> merg1_100;
	vector<int> merg2_100;
	vector<int> merg1_250;
	vector<int> merg2_250;
	vector<int> merg1_500;
	vector<int> merg2_500;
	vector<int> merg1_750;
	vector<int> merg2_750;
	vector<int> merg1_1000;
	vector<int> merg2_1000;
	vector<int> merged;
	
	
public:
	 LONGLONG startTime = 0, endTime =0, m_freqCount=0;

	void test();
	void bubble_sort_test(vector<int>& vec);
	void quick_sort_test(vector<int>& vec);
	void heap_sort_test(vector<int>& vec);

	void binary_search_test(vector<int>& vec, int x);
	void jump_search_test(vector<int>& vec, int x);
	void fibanacci_search_test(vector<int>& vec, int x);

	void merge_test(vector<int>& vec1, vector<int>& vec2);

	void display_test1(vector<int> vec);
	void create_test1(vector<int>& vec, int vecSize);
	void create_test2(int arr[]);
	
	void create_offset_test1(vector<int>& vec, int vecSize);
	void create_offset_test2(vector<int>& vec, int vecSize);
	
	void clearTime()
	{
		startTime = 0;
		endTime = 0;
		m_freqCount = 0;
	}
	
	
};

