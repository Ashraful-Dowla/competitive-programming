/*
https://atcoder.jp/contests/abc350/tasks/abc350_f
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
string s;
vector<int> mp(N, -1);

void rec(int l, int r, bool flip) {

	if (!flip) {
		while (l <= r) {
			if (s[l] == '(') {
				rec(l + 1, mp[l] - 1, 1 ^ flip);
				l = mp[l];
			}
			else {
				cout << s[l];
			}
			l++;
		}
	}
	else {
		while (l <= r) {
			if (s[r] == ')') {
				rec(mp[r] + 1, r - 1, 1 ^ flip);
				r = mp[r];
			}
			else {
				cout << s[r];
			}
			r--;
		}
	}
}

int main() {

	cin >> s;

	int h = 0, n = s.size();
	stack<int> stk;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			stk.push(i);
			h++;
		}
		else if (s[i] == ')') {
			mp[stk.top()] = i;
			mp[i] = stk.top();
			stk.pop();
			h--;
		}
		else if (h & 1) {
			s[i] ^= (1 << 5);
		}
	}

	rec(0, n - 1, 0);
}