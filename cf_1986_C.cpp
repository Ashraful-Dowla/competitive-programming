//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1986/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	set<int> st;

	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		st.insert(x - 1);
	}

	multiset<char> ms;
	for (int i = 0; i < m; ++i) {
		char ch;
		cin >> ch;
		ms.insert(ch);
	}

	for (int i = 0; i < n; ++i) {
		if (st.find(i) != st.end()) {
			s[i] = *ms.begin();
			ms.erase(ms.find(s[i]));
		}
	}

	cout << s << endl;
}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}