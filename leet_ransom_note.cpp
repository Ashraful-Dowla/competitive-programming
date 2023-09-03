/*
https://leetcode.com/problems/ransom-note/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {

	vector<int> fq(30, 0);

	for (char ch : magazine) {
		int idx = ch - 'a';
		fq[idx]++;
	}

	for (char ch : ransomNote) {
		int idx = ch - 'a';
		fq[idx]--;

		if (fq[idx] == -1) {
			return false;
		}
	}

	return true;

}

int main() {

	// string ransomNote = "a";
	// string magazine = "b";

	string ransomNote = "aa";
	string magazine = "ab";

	// string ransomNote = "aa";
	// string magazine = "aab";

	cout << canConstruct(ransomNote, magazine) << endl;
}