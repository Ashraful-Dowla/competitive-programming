/*
https://leetcode.com/problems/find-the-closest-palindrome/submissions/1366544703/?envType=daily-question&envId=2024-08-24
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll num, bool evn) {

	ll res = num;
	if (!evn) {
		res /= 10;
	}

	while (num > 0) {
		ll rem = num % 10;
		res = res * 10 + rem;
		num /= 10;
	}

	return res;
}

ll pw(ll a, ll b) {

	ll res = 1;
	for (int i = 0; i < b; ++i) {
		res *= a;
	}
	return res;
}

string nearestPalindromic(string n) {

	int sz = n.size();
	int k = sz % 2 == 0 ? sz / 2 - 1 : sz / 2;

	ll first = stoll(n.substr(0, k + 1));

	vector<ll> res;

	res.push_back(solve(first, sz % 2 == 0));
	res.push_back(solve(first + 1, sz % 2 == 0));
	res.push_back(solve(first - 1, sz % 2 == 0));
	res.push_back(pw(10, sz) + 1);
	res.push_back(pw(10, sz - 1) - 1);

	ll num =  stoll(n), diff = 1e18, ans = 0;

	for (ll x : res) {
		if (x == num) continue;
		if (abs(x - num) < diff) {
			diff = abs(x - num);
			ans = x;
		}
		else if (abs(x - num) == diff) {
			ans = min(ans, x);
		}
	}

	return to_string(ans);
}

int main() {

	// string n = "123";
	// string n = "0";
	string n = "123456";
	cout << nearestPalindromic(n) << endl;
}