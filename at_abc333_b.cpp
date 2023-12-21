/*
https://atcoder.jp/contests/abc333/tasks/abc333_b
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	string s, t;
	cin >> s;
	cin >> t;

	set<string> line = {"AB", "BA", "BC", "CB", "CD", "DC", "DE", "ED", "AE", "EA"};
	set<string> diagonal = {
		"AC", "EC", "CA", "CE",
		"BE", "BD", "EB", "DB",
		"AD", "AC", "DA", "CA"
	};

	if (line.find(s) != line.end() && line.find(t) != line.end()) {
		cout << "Yes" << endl;
	}
	else if (diagonal.find(s) != diagonal.end() && diagonal.find(t) != diagonal.end()) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}