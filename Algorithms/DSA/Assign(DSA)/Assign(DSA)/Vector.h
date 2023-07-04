#pragma once
#include <vector>
#include <iostream>

using namespace std;
template <typename T>
class myVector
{
public:
	T last_vec(vector<T&> vec)
	{
		T last;
		vec.back(last);
		return last;
		
	}
	//=================================insert============================//
	void insertFront(vector<T>& vec, T& item)
	{
		vec.insert(vec.begin(),item);
	}
	void insert(vector<T>& vec, T& pos, T& item)
	{
		vec.insert(pos, item);
	}
	void pushBack(vector<T>& vec, T& item)
	{
		vec.push_back(item);
	}
	//================================display vectors=====================//
	void display_vec(vector<T> vec)
	{
		//sort(m_test1.begin(), m_test1.end());
		for (unsigned int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << '\t';
		}
		cout << endl;
	}
//=======================creating vectors=================================//
	void create_vec(vector<T>& vec, int vecSize)
	{
		for (int i = 1; i <= vecSize; i++)
		{
			vec.push_back(i);
		}
	}

	void create_offset_vec_x1(vector<int>& vec, int vecSize)
	{
		for (int i = 1; i <= vecSize; i++)
		{
			vec.push_back(i);
			i++;
		}
	}
	void create_offset_x2(vector<int>& vec, int vecSize)
	{
		for (int i = 2; i <= vecSize; i++)
		{
			vec.push_back(i);
			i++;
		}
	}
};

