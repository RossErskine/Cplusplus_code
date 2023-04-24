#include <algorithm>

int maximumToys(vector<int> prices, int k) {
    int sum = 0;
    sort(prices.begin(),prices.end());
    for (int i = 0; i != prices.size(); i++) {
        sum += prices[i];
        if (sum > k) {
            return i;
        }
    }
    return 0;
}

void countSwaps(vector<int> a) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {

        for (int j = 0; j < a.size() - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                count++;
            }
        }

    }
    std::cout << "Array is sorted in " << count << " swaps.\n";
    std::cout << "First Element: " << a[0] << '\n';
    std::cout << "Last Element: " << a[a.size() - 1] << '\n';
}

void runSorting()
{
    vector<int> a = { 3,2,1 };
    //countSwaps(a);

    vector<int> prices = { 1,12,5,111,1000,10 };
    int k = 50;
    std::cout << maximumToys(prices, k);

}
