/*
https://leetcode.com/problems/number-of-wonderful-substrings/description/?envType=daily-question&envId=2024-04-30
*/
#include <bits/stdc++.h>
using namespace std;

long long wonderfulSubstrings(string word) {

	long long ans = 0, mask = 0;
	map<long long, long long> mp;
	mp[0] = 1;

	for (char ch : word) {
		int idx = ch - 'a';
		mask ^= (1LL << idx);
		ans += mp[mask];

		for (int i = 0; i < 10; ++i) {
			ans += mp[mask ^ (1LL << i)];
		}
		mp[mask]++;
	}

	return ans;
}

int main() {

	string word = "he";
	cout << wonderfulSubstrings(word) << endl;
}