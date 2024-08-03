/*
https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01
*/
#include <bits/stdc++.h>
using namespace std;

int countSeniors(vector<string>& details) {

	int ans = 0;
	for (string s : details) {
		if (stoi(s.substr(11, 2)) > 60) {
			ans++;
		}
	}

	return ans;
}

int main() {

	vector<string> details = {"7868190130M7522", "5303914400F9211", "9273338290F4010"};

	cout << countSeniors(details) << endl;
}