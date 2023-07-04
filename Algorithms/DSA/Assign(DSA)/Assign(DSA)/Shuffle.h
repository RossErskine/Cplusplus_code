#include <iostream>

using namespace std;
template <typename T>
class Shuffle
{
	
public:
	
	void shuffle(vector<T>& arrName)
	{
		//shuffle
		for (unsigned int i = 0; i < arrName.size(); i++)
		{
			//swap
			int rnd = rand() % arrName.size();
			T& temp = arrName[rnd];
			arrName[rnd] = arrName[i];
			arrName[i] = temp;
			
		}
	}

	void std_shuffle(vector<T>& vec)
	{
		random_shuffle(vec.begin(), vec.end());
	}
	
};