/*
https://leetcode.com/problems/happy-number/description/
*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool>mp;

int sum(int n) {

	int res = 0;
	while (n) {
		int x = n % 10;
		res += (x * x);
		n /= 10;
	}

	return res;
}

bool isHappy(int n) {

	while (true) {
		n = sum(n);
		if (mp[n]) break;
		mp[n] = true;
	}

	return n == 1;
}

int main() {

	int n = 14;

	for (int i = 1; i <= 20; ++i) {
		cout << i << " " << isHappy(i) << endl;
	}
}