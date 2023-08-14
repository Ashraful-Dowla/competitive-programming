/*
https://leetcode.com/problems/integer-to-english-words/description/
*/
#include <bits/stdc++.h>
using namespace std;

map<int, string> numbers{
	{0, "Zero"},
	{1, "One"},
	{2, "Two"},
	{3, "Three"},
	{4, "Four"},
	{5, "Five"},
	{6, "Six"},
	{7, "Seven"},
	{8, "Eight"},
	{9, "Nine"},
	{10, "Ten"},
	{11, "Eleven"},
	{12, "Twelve"},
	{13, "Thirteen"},
	{14, "Fourteen"},
	{15, "Fifteen"},
	{16, "Sixteen"},
	{17, "Seventeen"},
	{18, "Eighteen"},
	{19, "Nineteen"},
	{20, "Twenty"},
	{30, "Thirty"},
	{40, "Forty"},
	{50, "Fifty"},
	{60, "Sixty"},
	{70, "Seventy"},
	{80, "Eighty"},
	{90, "Ninety"},
};

map<int, string> mp = {
	{0, "Hundred"},
	{1, "Thousand"},
	{2, "Million"},
	{3, "Billion"}
};

string numberToWords(int num) {

	if (num == 0) {
		return numbers[num];
	}

	string s = to_string(num);
	reverse(s.begin(), s.end());
	int n = s.size();

	vector<string> vec;
	for (int i = 0; i < n; i += 3) {

		string t = s.substr(i, 3);
		reverse(t.begin(), t.end());

		int v = stoi(t);
		t = to_string(v);

		int sz = t.size();
		string res;

		if (sz == 3) {

			res += numbers[t[0] - '0'];
			res = res + " " + mp[0];

			int tt = stoi(t.substr(1));

			if (tt > 0 && tt <= 20) {
				res = res + " " + numbers[tt];
			}
			else {
				if (t[1] != '0') {
					res = res + " " + numbers[(t[1] - '0') * 10];
				}
				if (t[2] != '0') {
					res = res + " " + numbers[t[2] - '0'];
				}
			}

		}
		else if (sz == 2) {

			int tt = stoi(t.substr(0));
			if (tt <= 20) {
				res += numbers[tt];
			}
			else {
				res += numbers[(t[0] - '0') * 10];
				if (t[1] != '0') {
					res = res + " " + numbers[t[1] - '0'];
				}
			}

		}
		else if (sz == 1) {
			if (t[0] != '0') {
				res += numbers[t[0] - '0'];
			}
		}

		int p = i / 3;
		if (res.size() > 0) {
			string st = res;
			if (p > 0) {
				st += " " + mp[p];
			}
			vec.push_back(st);
		}
	}

	reverse(vec.begin(), vec.end());

	string ans = vec[0];
	for (int i = 1; i < vec.size(); ++i) {
		ans = ans + " " + vec[i];
	}

	return ans;
}

int main() {

	// int num = 123;
	// int num = 12345;
	// int num = 1003000021;
	int num = 0;
	// int num = 1000;

	cout << numberToWords(num) << endl;
}