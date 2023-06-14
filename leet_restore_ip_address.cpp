/*
https://leetcode.com/problems/restore-ip-addresses/description/
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
string ip;
int n;

bool isValid(string s, int i, int len) {
	string st = s.substr(i, len);
	return stoi(st) >= 0 && stoi(st) <= 255;
}

void solve(string s, int i, int k) {

	if (i == n && k == 0) {
		ans.push_back(ip.substr(0, ip.size() - 1));
		return ;
	}

	if (i < n && isValid(s, i, 1)) {

		char ch = s[i];
		ip.push_back(ch);
		ip.push_back('.');

		solve(s, i + 1, k - 1);

		for (int j = 0; j < 2; ++j) {
			ip.pop_back();
		}

	}
	if (i + 1 < n  && s[i] != '0' && isValid(s, i, 2)) {

		for (int j = 0; j < 2; ++j) {
			char ch = s[i + j];
			ip.push_back(ch);
		}
		ip.push_back('.');

		solve(s, i + 2, k - 1);

		for (int j = 0; j < 3; ++j) {
			ip.pop_back();
		}

	}
	if (i + 2 < n && s[i] != '0' && isValid(s, i, 3)) {

		for (int j = 0; j < 3; ++j) {
			char ch = s[i + j];
			ip.push_back(ch);
		}
		ip.push_back('.');

		solve(s, i + 3, k - 1);

		for (int j = 0; j < 4; ++j) {
			ip.pop_back();
		}
	}
}

vector<string> restoreIpAddresses(string s) {
	n = s.size();
	solve(s, 0, 4);
	return ans;
}

int main() {
	// string s = "25525511135";
	// string s = "0000";
	// string s = "101023";
	string s = "010010";

	auto res = restoreIpAddresses(s);

	for (string r : res) {
		cout << r << endl;
	}
	cout << endl;
}