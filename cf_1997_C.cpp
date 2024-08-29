//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1997/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	stack<int> stk;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		char ch = s[i];
		if (ch == '_') {
			if (!stk.empty() && s[stk.top()] == '(') {
				ans += i - stk.top();
				stk.pop();
			}
			else {
				stk.push(i);
			}
		}
		else if (ch == ')') {
			if (!stk.empty() && s[stk.top()] != ')') {
				ans += i - stk.top();
				stk.pop();
			}
			else {
				stk.push(i);
			}
		}
		else {
			stk.push(i);
		}
	}

	cout << ans << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}