/*
https://atcoder.jp/contests/abc312/tasks/abc312_a
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s;
	cin >> s;

	if (s == "ACE" || s == "BDF" || s == "CEG" || s == "DFA"
	        || s == "EGB" || s == "FAC" || s == "GBD") {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}