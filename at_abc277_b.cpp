/*
https://atcoder.jp/contests/abc277/tasks/abc277_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	set<char> s1 = {'H', 'D', 'C', 'S'};
	set<char> s2 = {'A', '2', '3', '4', '5', '6', '7', '8', '9',
	                'T', 'J', 'Q', 'K'
	               };

	for (int i = 0; i < n; ++i) {
		string s = v[i];
		if (s1.find(s[0]) == s1.end() || s2.find(s[1]) == s2.end()) {
			cout << "No" << endl;
			return 0;
		}
		else {
			for (int j = i + 1; j < n; ++j) {
				if (s == v[j]) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}

	cout << "Yes" << endl;
}