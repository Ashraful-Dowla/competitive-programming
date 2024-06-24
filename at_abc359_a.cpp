/*
https://atcoder.jp/contests/abc359/tasks/abc359_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	map<string, int> mp;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		mp[s]++;
	}

	cout << mp["Takahashi"] << endl;
}