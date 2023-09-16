/*
https://leetcode.com/problems/binary-watch/
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> res;
unordered_map<string, bool>taken;

bool isValid(int h, int m) {
	return h >= 0 && h <= 11 && m >= 0 && m <= 59;
}

void solve(vector<int>& hours, vector<int>& minutes, int h, int m, int i, int j, int k) {

	if (k < 0) return ;
	if (k == 0) {
		string hh = to_string(h);

		string mm = to_string(m);
		if (m < 10) {
			mm = "0" + mm;
		}

		string t = hh + ":" + mm;

		if (isValid(h, m) && !taken[t]) {
			res.push_back(t);
			taken[t] = true;
		}

		return ;
	}
	if (i >= hours.size() || j >= minutes.size()) return ;

	solve(hours, minutes, h, m, i + 1, j, k);
	solve(hours, minutes, h + hours[i], m, i + 1, j, k - 1);

	solve(hours, minutes, h, m, i, j + 1, k);
	solve(hours, minutes, h, m + minutes[j], i, j + 1, k - 1);

	solve(hours, minutes, h, m, i + 1, j + 1, k);
	solve(hours, minutes, h + hours[i], m + minutes[j], i + 1, j + 1, k - 2);

}

vector<string> readBinaryWatch(int turnedOn) {

	vector<int> hours = {8, 4, 2, 1};
	vector<int> minutes = {32, 16, 8, 4, 2, 1};

	solve(hours, minutes, 0, 0, 0, 0, turnedOn);
	sort(res.begin(), res.end());

	return res;
}

int main() {

	int turnedOn = 0;

	auto ans = readBinaryWatch(turnedOn);

	for (string s : ans) {
		cout << s << endl;
	}
}