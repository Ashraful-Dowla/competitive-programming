/*
https://leetcode.com/problems/maximum-product-of-word-lengths/description/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int maxProduct(vector<string>& words) {

	vector<ll> w(words.size(), 0);

	for (int i = 0; i < words.size(); ++i) {
		for (int j = 0; j < words[i].size(); ++j) {
			w[i] |= (1 << (words[i][j] - 'a'));
		}
	}

	ll ans = 0;

	for (int i = 0; i < words.size(); ++i) {
		for (int j = i + 1; j < words.size(); ++j) {

			if ((w[i]&w[j]) == 0) {
				ll len = words[i].size() * words[j].size();
				ans = max(ans, len);
			}
		}
	}

	return ans;
}

int main() {

	// vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	// vector<string> words = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
	// vector<string> words = {"a", "aa", "aaa", "aaaa"};
	vector<string> words = {"eae", "ea", "aaf", "bda", "fcf", "dc", "ac", "ce", "cefde", "dabae"};
	cout << maxProduct(words);
}