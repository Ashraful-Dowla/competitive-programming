/*
https://atcoder.jp/contests/abc279/tasks/abc279_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;
	string t;
	cin >> t;

	if (s.find(t) != std::string::npos) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}