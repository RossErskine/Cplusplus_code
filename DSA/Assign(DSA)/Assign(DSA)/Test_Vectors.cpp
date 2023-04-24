#include "Test_Vectors.h"
#include "Shuffle.h"
#include "Bubble_Sort.h"
#include "Quick_Sort.h"
#include "Heap_sort.h"
#include "Binary_search.h"
#include "Jump_search.h"
#include "Fibonacci_search.h"
#include "Merge.h"
#include "Delete.h"
#include "Insert.h"


//========declorations========//
Test_Vectors tv;
Shuffle<int> sh;
Bubble_Sort<int> bs;
Quick_Sort<int> qs;
Heap_sort<int> hs;
Binary_search<int> bns;
Jump_search<int> js;
Fibonacci_search<int> fs;
Merge<int> mg;
Delete dt;
Insert in;


void Test_Vectors::test()
{
	//=================create tests================//
	tv.create_test1(temp10, 10);
	tv.create_test1(temp50, 50);
	tv.create_test1(temp100, 100);
	tv.create_test1(temp250, 250);
	tv.create_test1(temp500, 500);
	tv.create_test1(temp750, 750);
	tv.create_test1(temp1000, 1000);

	tv.create_offset_test1(merg1_10, 10);
	tv.create_offset_test2(merg2_10, 10);
	tv.create_offset_test1(merg1_50, 50);
	tv.create_offset_test2(merg2_50, 50);
	tv.create_offset_test1(merg1_100, 100);
	tv.create_offset_test2(merg2_100, 100);
	tv.create_offset_test1(merg1_250, 250);
	tv.create_offset_test2(merg2_250, 250);
	tv.create_offset_test1(merg1_500, 500);
	tv.create_offset_test2(merg2_500, 500);
	tv.create_offset_test1(merg1_750, 750);
	tv.create_offset_test2(merg2_750, 750);
	tv.create_offset_test1(merg1_1000, 1000);
	tv.create_offset_test2(merg2_1000, 1000);
	//====initialisation for target searches=====//
	//======Test 1======//
	int T1x1 = 7;  //vector 10 target
	int T1x2 = 29;  //vector 50 target
	int T1x3 = 76;	//vector 100 target
	int T1x4 = 133;	//vector 250 target
	int T1x5 = 499;	//vector 500 target
	int T1x6 = 501;	//vector 750 target
	int T1x7 = 907;	//vector 1000 target
	//======Test 2=====//
	int T2x1 = 3;	//vector 10 target
	int T2x2 = 14;	//vector 50 target
	int T2x3 = 41;	//vector 100 target
	int T2x4 = 101;	//vector 250 target
	int T2x5 = 249;	//vector 500 target
	int T2x6 = 301;	//vector 750 target
	int T2x7 = 435;	//vector 1000 target
	//==delete & insert target==//
	int x = 8;
	int y = 5;
	//===============test menu=================//
	bool Vtest = true;
	while (Vtest == true)
	{
		int choice;

		cout << "**Please choose from test menu:**" << endl;
		cout << "*********** Test Menu ***********" << endl;
		cout << "***1) Bubble sort             ***" << endl;
		cout << "***2) Quick sort              ***" << endl;
		cout << "***3) Heap sort               ***" << endl;
		cout << "***4) Binary search           ***" << endl;
		cout << "***5) Jump search             ***" << endl;
		cout << "***6) Fibanacci search        ***" << endl;
		cout << "***7) merg algorithm          ***" << endl;
		cout << "***8) Delete & Insert         ***" << endl;
		cout << "***0) Quit                    ***" << endl;
		cout << "***                           ***" << endl;
		cout << "*********************************" << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			Vtest = false;
			break;
		case 1:
			sh.shuffle(temp10);
			sh.shuffle(temp50);
			sh.shuffle(temp100);
			sh.shuffle(temp250);
			sh.shuffle(temp500);
			sh.shuffle(temp750);
			sh.shuffle(temp1000);
			//===================bubble sort test ===============//
			cout << "Bubble sorted vector: 10 elements" << endl;
			bubble_sort_test(temp10);
			cout << "Bubble sorted vector: 50 elements" << endl;
			bubble_sort_test(temp50);
			cout << "Bubble sorted vector: 100 elements" << endl;
			bubble_sort_test(temp100);
			cout << "Bubble sorted vector: 250 elements" << endl;
			bubble_sort_test(temp250);
			cout << "Bubble sorted vector: 500 elements" << endl;
			bubble_sort_test(temp500);
			cout << "Bubble sorted vector: 750 elements" << endl;
			bubble_sort_test(temp750);
			cout << "Bubble sorted vector: 1000 elements" << endl;
			bubble_sort_test(temp1000);
			break;
		case 2:
			sh.shuffle(temp10);
			sh.shuffle(temp50);
			sh.shuffle(temp100);
			sh.shuffle(temp250);
			sh.shuffle(temp500);
			sh.shuffle(temp750);
			sh.shuffle(temp1000);
			//==================quick sort========================//
			cout << "Quick sorted vector: 10 elements" << endl;
			quick_sort_test(temp10);
			cout << "Quick sorted vector: 50 elements" << endl;
			quick_sort_test(temp50);
			cout << "Quick sorted vector: 100 elements" << endl;
			quick_sort_test(temp100);
			cout << "Quick sorted vector: 250 elements" << endl;
			quick_sort_test(temp250);
			cout << "Quick sorted vector: 500 elements" << endl;
			quick_sort_test(temp500);
			cout << "Quick sorted vector: 750 elements" << endl;
			quick_sort_test(temp750);
			cout << "Quick sorted vector: 1000 elements" << endl;
			quick_sort_test(temp1000);
			break;
		case 3:
			sh.shuffle(temp10);
			sh.shuffle(temp50);
			sh.shuffle(temp100);
			sh.shuffle(temp250);
			sh.shuffle(temp500);
			sh.shuffle(temp750);
			sh.shuffle(temp1000);
			//=================Heap sort=========================//
			cout << " Heap sorted vectors: 10 elements " << endl;
			heap_sort_test(temp10);
			cout << " Heap sorted vectors: 50 elements " << endl;
			heap_sort_test(temp50);
			cout << " Heap sorted vectors: 100 elements " << endl;
			heap_sort_test(temp100);
			cout << " Heap sorted vectors: 250 elements " << endl;
			heap_sort_test(temp250);
			cout << " Heap sorted vectors: 500 elements " << endl;
			heap_sort_test(temp500);
			cout << " Heap sorted vectors: 750 elements " << endl;
			heap_sort_test(temp750);
			cout << " Heap sorted vectors: 1000 elements " << endl;
			heap_sort_test(temp1000);

			break;
		case 4:
			//================binary search====================//
			//================Test 1=============//
			cout << " =============Binary Search Test 1============" << endl;
			cout << "Binary search: 10 elements " << endl;
			binary_search_test(temp10, T1x1);
			cout << "Binary search: 50 elements " << endl;
			binary_search_test(temp50, T1x2);
			cout << "Binary search: 100 elements " << endl;
			binary_search_test(temp100, T1x3);
			cout << "Binary search: 250 elements " << endl;
			binary_search_test(temp250, T1x4);
			cout << "Binary search: 500 elements " << endl;
			binary_search_test(temp500, T1x5);
			cout << "Binary search: 750 elements " << endl;
			binary_search_test(temp750, T1x6);
			cout << "Binary search: 1000 elements " << endl;
			binary_search_test(temp1000, T1x7);
			
			//================Test 2=============//
			cout << " ===========Binary Search Test 2=============" << endl;
			cout << "Binary search: 10 elements " << endl;
			binary_search_test(temp10, T2x1);
			cout << "Binary search: 50 elements " << endl;
			binary_search_test(temp50, T2x2);
			cout << "Binary search: 100 elements " << endl;
			binary_search_test(temp100, T2x3);
			cout << "Binary search: 250 elements " << endl;
			binary_search_test(temp250, T2x4);
			cout << "Binary search: 500 elements " << endl;
			binary_search_test(temp500, T2x5);
			cout << "Binary search: 750 elements " << endl;
			binary_search_test(temp750, T2x6);
			cout << "Binary search: 1000 elements " << endl;
			binary_search_test(temp1000, T2x7);
			break;
		case 5:
			//=============jump search===========================//
			//============Test 1=============//
			cout << " =============jump search Test 1===========" << endl;
			cout << "Jump search: 10 elements " << endl;
			jump_search_test(temp10, T1x1);
			cout << "Jump search: 50 elements " << endl;
			jump_search_test(temp50, T1x2);
			cout << "Jump search: 100 elements " << endl;
			jump_search_test(temp100, T1x3);
			cout << "Jump search: 250 elements " << endl;
			jump_search_test(temp250, T1x4);
			cout << "Jump search: 500 elements " << endl;
			jump_search_test(temp500, T1x5);
			cout << "Jump search: 750 elements " << endl;
			jump_search_test(temp750, T1x6);
			cout << "Jump search: 1000 elements " << endl;
			jump_search_test(temp1000, T1x7);
			//============Test 2=============//
			cout << " ============jump search Test 2============" << endl;
			cout << "Jump search: 10 elements " << endl;
			jump_search_test(temp10, T2x1);
			cout << "Jump search: 50 elements " << endl;
			jump_search_test(temp50, T2x2);
			cout << "Jump search: 100 elements " << endl;
			jump_search_test(temp100, T2x3);
			cout << "Jump search: 250 elements " << endl;
			jump_search_test(temp250, T2x4);
			cout << "Jump search: 500 elements " << endl;
			jump_search_test(temp500, T2x5);
			cout << "Jump search: 750 elements " << endl;
			jump_search_test(temp750, T2x6);
			cout << "Jump search: 1000 elements " << endl;
			jump_search_test(temp1000, T2x7);
			break;
		case 6:
			//=============Fibanacci search=====================//
			//================Test 1 ===============//
			cout << "=============Fibanacci search Test 1===============" << endl;
			cout << "Fibanacci search: 10 elements " << endl;
			fibanacci_search_test(temp10, T1x1);
			cout << "Fibanacci search: 50 elements " << endl;
			fibanacci_search_test(temp50, T1x2);
			cout << "Fibanacci search: 100 elements " << endl;
			fibanacci_search_test(temp100, T1x3);
			cout << "Fibanacci search: 250 elements " << endl;
			fibanacci_search_test(temp250, T1x4);
			cout << "Fibanacci search: 500 elements " << endl;
			fibanacci_search_test(temp500, T1x5);
			cout << "Fibanacci search: 750 elements " << endl;
			fibanacci_search_test(temp750, T1x6);
			cout << "Fibanacci search: 1000 elements " << endl;
			fibanacci_search_test(temp1000, T1x7);
			//================Test 2 ===============//
			cout << "============Fibanacci search Test 2============" << endl;
			cout << "Fibanacci search: 10 elements " << endl;
			fibanacci_search_test(temp10, T2x1);
			cout << "Fibanacci search: 50 elements " << endl;
			fibanacci_search_test(temp50, T2x2);
			cout << "Fibanacci search: 100 elements " << endl;
			fibanacci_search_test(temp100, T2x3);
			cout << "Fibanacci search: 250 elements " << endl;
			fibanacci_search_test(temp250, T2x4);
			cout << "Fibanacci search: 500 elements " << endl;
			fibanacci_search_test(temp500, T2x5);
			cout << "Fibanacci search: 750 elements " << endl;
			fibanacci_search_test(temp750, T2x6);
			cout << "Fibanacci search: 1000 elements " << endl;
			fibanacci_search_test(temp1000, T2x7);
			break;
		case 7:
			//============merg algorithm=========================//
			cout << "merge: 10 elements" << endl;
			merge_test(merg1_10, merg2_10);
			cout << "merge: 50 elements" << endl;
			merge_test(merg1_50, merg2_50);
			cout << "merge: 100 elements" << endl;
			merge_test(merg1_100, merg2_100);
			cout << "merge: 250 elements" << endl;
			merge_test(merg1_250, merg2_250);
			cout << "merge: 500 elements" << endl;
			merge_test(merg1_500, merg2_500);
			cout << "merge: 750 elements" << endl;
			merge_test(merg1_750, merg2_750);
			cout << "merge: 1000 elements" << endl;
			merge_test(merg1_1000, merg2_1000);
			break;
		case 8:
			//================delete & insert==============================//
			dt.deleteElement(temp10, x);
			tv.display_test1(temp10);
			in.insertSorted(temp10, y);
			tv.display_test1(temp10);
			break;
		default:
			cout << " a number was not picked! " << endl;
			break;
		}
	}
}
void Test_Vectors::merge_test(vector<int>& vec1, vector<int>& vec2)
{
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
	vector<int> MGTest1 = vec1;
	vector<int> MGTest2 = vec2;
	merged = mg.merge_vectors(vec1, vec2);
	//tv.display_test1(merged); //========show test========//
	cout << "Iterations: " << mg.GetIteration() << endl;
	mg.clearIteretions();
	QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
	cout << " time taken: " << endTime - startTime << "ms" << endl << endl;

}
void Test_Vectors::fibanacci_search_test(vector<int>& vec, int x)
{
	vector<int> FSTest = vec;
	
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
	int index = fs.fibMonaccianSearch(FSTest, x, FSTest.size());
	cout << "Number " << x << " is at index " << index << endl;
	cout << "Iterations: " << fs.GetIteration() << endl;
	fs.clearIteretions();
	QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
	cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
	tv.clearTime();

}
void Test_Vectors::jump_search_test(vector<int>& vec, int x)
{
	vector<int> JSTest = vec;
	
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
	int index = js.jumpSearch(JSTest, x, JSTest.size());
	cout << "Number " << x << " is at index " << index << endl;
	cout << "Iterations: " << js.GetIteration() << endl;
	js.clearIteretions();
	QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
	cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
	tv.clearTime();
	
}
void Test_Vectors::binary_search_test(vector<int>& vec, int x)
{
	vector<int> BNSTest = vec;
	
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
	int result = bns.binarySearch_vec(BNSTest,0, BNSTest.size() - 1,x);//return result and index
	(result == -1) ? cout << "Element was not found "
		: cout << "Element found at index: " << result << endl;
	cout << "Iterations: " << bns.GetIteration() << endl;
	bns.clearIteretions();
	QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
	cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
	tv.clearTime();
	
}

void Test_Vectors::heap_sort_test(vector<int>& vec)
{
	vector<int> HSTest = vec;
	
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
	hs.heapSort(HSTest);
	//tv.display_test1(HSTest);//========show test========//
	cout << "Iterations: " << hs.GetIteration() << endl;
	cout << "Swaps: " << hs.GetSwaps() << endl;
	hs.clearIteretions();
	hs.clearSwaps();
	QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
	cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
	tv.clearTime();
}
void Test_Vectors::quick_sort_test(vector<int>& vec)
{
	vector<int> QSTest = vec;
	
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
	qs.quickSort(QSTest, 0, QSTest.size() - 1);
	//tv.display_test1(QSTest);//========show test========//
	cout << "Iterations: " << qs.GetIteration() << endl;
	cout << "Swaps: " << qs.GetSwaps() << endl;
	qs.clearIteretions();
	qs.clearSwaps();
	QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
	cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
	tv.clearTime();
}

void Test_Vectors::bubble_sort_test(vector<int>& vec)
{
	vector<int> BSTest = vec;
	
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);//start time taken
	bs.bubble_sort(BSTest);
	//tv.display_test1(BSTest);//========show test========//
	cout << "Iterations: " << bs.GetIteration() << endl;
	cout << "Swaps: " << bs.GetSwaps() << endl;
	bs.clearIteretions();
	bs.clearSwaps();
	QueryPerformanceCounter((LARGE_INTEGER*)&endTime);//end time taken
	cout << " time taken: " << endTime - startTime << "ms" << endl << endl;
	tv.clearTime();
}


void Test_Vectors::display_test1(vector<int> vec)
{
	//sort(m_test1.begin(), m_test1.end());
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << '\t';
	}
	cout << endl;
}

void Test_Vectors::create_test1(vector<int>& vec, int vecSize)
{
	for (int i = 1; i <= vecSize; i++)
	{
		vec.push_back(i);
	}
}

/*void Test_Vectors::create_test2(int arr[])
{
	for (int i = 1; i <= n; i++)
	{
		arr[i];
	}
}*/

void Test_Vectors::create_offset_test1(vector<int>& vec, int vecSize)
{
	for (int i = 1; i <= vecSize; i++)
	{
		vec.push_back(i);
		i++;
	}
}
void Test_Vectors::create_offset_test2(vector<int>& vec, int vecSize)
{
	for (int i = 2; i <= vecSize; i++)
	{
		vec.push_back(i);
		i++;
	}
}



