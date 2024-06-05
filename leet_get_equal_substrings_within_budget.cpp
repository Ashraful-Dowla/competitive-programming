#include <bits/stdc++.h>
using namespace std;

int pf[1000005];

int can(int n, int k) {

	int mn = INT_MAX;
	for (int i = k; i <= n; ++i) {
		mn = min(mn, pf[i] - pf[i - k]);
	}

	return mn;
}

int equalSubstring(string s, string t, int maxCost) {

	int n = s.size();
	s = "_" + s;
	t = "_" + t;

	for (int i = 1; i <= n; ++i) {
		pf[i] = pf[i - 1] + abs(s[i] - t[i]);
	}

	int lo = 1, hi = n, ans = 0;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (can(n, mid) <= maxCost) {
			lo = mid + 1;
			ans = mid;
		}
		else {
			hi = mid - 1;
		}
	}

	return ans;
}

int main() {

	string s = "abcd";
	string t = "bcdf";
	int maxCost = 3;

	// string s = "abcd";
	// string t = "cdef";
	// int maxCost = 3;

	cout << equalSubstring(s, t, maxCost) << endl;
}