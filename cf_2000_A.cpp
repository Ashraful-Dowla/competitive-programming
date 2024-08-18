//Author: Ashraful Dowla
/*
https://codeforces.com/contest/2000/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {

	string s;
	cin >> s;

	if (s.size() > 2 && s[0] == '1' && s[1] == '0') {

		if (s[2] == '0') {
			cout << "NO" << endl;
			return ;
		}

		string p = s.substr(2);
		if (stoi(p) < 2) {
			cout << "NO" << endl;
			return ;
		}

		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}

int main() {
	Faster;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}