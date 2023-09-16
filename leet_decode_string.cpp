/*
https://leetcode.com/problems/decode-string/description/
*/
#include <bits/stdc++.h>
using namespace std;

string solve(string& s) {

	stack<string> stk;
	string num, t;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			num.push_back(s[i]);
			if (t.size()) {
				stk.push(t);
				t = "";
			}
		}
		else if (s[i] == '[') {
			stk.push(num);
			stk.push("[");
			num = "";
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			t.push_back(s[i]);
		}
		else {
			
			if (t.size()) {
				stk.push(t);
				t = "";
			}

			string q;
			while (!stk.empty() && stk.top() != "[") {
				q = stk.top() + q;
				stk.pop();
			}
			stk.pop();

			int num = stoi(stk.top());
			stk.pop();

			string res;
			for (int j = 0; j < num; ++j) {
				res += q;
			}

			stk.push(res);
		}
	}

	if (t.size()) {
		stk.push(t);
	}

	string ans;
	while (!stk.empty()) {
		ans = stk.top() + ans;
		stk.pop();
	}

	return ans;

}

string decodeString(string s) {
	return solve(s);
}

int main() {
	string s = "3[a]2[bc]";
	// string s = "3[a2[c]]";
	// string s = "2[abc]3[cd]ef";
	cout << decodeString(s) << endl;
}