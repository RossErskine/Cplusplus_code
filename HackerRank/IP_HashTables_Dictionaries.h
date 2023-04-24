#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

string twoStrings(string s1, string s2) {
	bool found = false;
	unordered_map<char, int> hash;
	for (int i = 0; i != s1.size(); i++) {
		hash[s1[i]]++; // make index
	}
	for (int i = 0; i != s2.size(); i++) {
		if (hash[s2[i]] >0) {
			found = true;
		}
	}

	if (found == true) {
		return "YES";
	}
	else {
		return "NO";
	}
}

void checkMagazine(vector<string> magazine, vector<string> note) {
	unordered_map<string, int> words;
	bool found = true;
	for (int i = 0; i != magazine.size(); i++) {
		words[magazine[i]]++; // makes index of item
	}
	for (int i = 0; i != note.size(); i++) {
		if (words[note[i]] > 0) words[note[i]]--;
		else found = false;
	}
	if (found == true) {
		std::cout << "Yes";
	}
	else {
		std::cout << "No";
	}

}

void runIP_Hash_Dict() {
	vector<string> magazine = { "give", "me", "one", "grand", "today", "night" };
	vector<string> note = { "give", "one", "grand", "today" };
	//checkMagazine(magazine, note);

	std::string a = "hello";
	std::string b = "world";
	std::cout << twoStrings(a, b) << std::endl;
}
