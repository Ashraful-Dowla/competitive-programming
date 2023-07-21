#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int lps[N];
string pattern, text;

//time complexity -> O(n)
void kmpPreprocess() {

	int n = pattern.size();
	int i = 0, j = 1;

	while (j < n) {
		while (i > 0 && pattern[i] != pattern[j]) {
			i = lps[i - 1];
		}

		if (pattern[i] == pattern[j]) {
			i++;
		}

		lps[j] = i;
		j++;
	}

	// for (int i = 0; i < n; ++i) {
	// 	cout << lps[i] << " ";
	// }
}

//time complexity -> O(m+n)
void kmpSearch() {

	int m = text.size();
	int n = pattern.size();

	int i = 0, j = 0;

	while (i < m) {
		while (j > 0 && text[i] != pattern[j]) {
			j = lps[j - 1];
		}

		if (j < n && text[i] == pattern[j]) {
			j++;
		}
		i++;

		if (j == n) {
			cout << i - n << endl;
		}
	}
}

int main() {

	text = "abxabcabcaby";
	pattern = "abcaby";
	// pattern = "aaacecaaaacecaaa";

	kmpPreprocess();
	kmpSearch();
}