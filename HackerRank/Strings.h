#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int alternatingCharacters(string s) {
	int deletions = 0;
	for (int i = 0; i != s.size() - 1; i++) {
		if (s[i] == s[i + 1]) deletions++;
	}
	return deletions;
}

int makeAnagram(string a, string b)
{
	int anagrams = 0;
	vector<int> hash(26, 0);
	for (auto i : a) {
		++hash[i - 'a'];
	}
	for (auto i : b) {
		--hash[i - 'a'];
	}
	for (auto i : hash) {
		anagrams += abs(i);
	}
	
	
	return  anagrams;
}

void runStrings()
{
	string a = "fcrxzwscanmligyxyvym";
	string b = "jxwtrhvujlmrpdoqbisbwhmgpmeoke";
	cout << '\n' << makeAnagram(a, b);
}
