#include <vector>
#include <iostream>

using namespace std;

void printArr(vector<int> arr) {
	for (int i = 0; i != arr.size(); i++) {
		cout << arr[i] << '\t';
	}
	cout << '\n';
}

// not finished as do not understand second test case
void minimumBribes(vector<int> q) {
	int swaps = 0;
	bool tooChaotic = false;
	for (int i = q.size()-1; i > 0; i--) {
		if (q[i] > i ) {
			int bribes = q[i] - i;
			if (bribes > 2) tooChaotic = true;
			swaps += bribes;
		}
	}
	cout << '\n' << swaps;
	if (tooChaotic == true) cout << "\nToo chaotic";
}

int minimumSwaps(vector<int> arr) {
	int minSwaps = 0;
	bool run = true;
	for (int i = 0; i != arr.size(); i++) {
		if (i + 1 != arr[i]) {
			int temp = i;
			while (arr[temp] != i + 1) {
				temp++;
			}
			int t = arr[temp];
			arr[temp] = arr[i];
			arr[i] = t;
			minSwaps++;
		}
	}
	return minSwaps;
}

void runArrays()
{
	vector<int> arr = { 2, 1, 5, 3, 4  };
	//cout << minimumSwaps(arr);

	minimumBribes(arr);
}
