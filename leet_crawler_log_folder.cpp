/*
https://leetcode.com/problems/crawler-log-folder/editorial/?envType=daily-question&envId=2024-07-10
*/
#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<string>& logs) {

	stack<string> stk;
	for (string log : logs) {

		if (log == "../") {
			if (!stk.empty()) {
				stk.pop();
			}
		}
		else if (log == "./") {
			continue;
		}
		else {
			stk.push(log);
		}
	}

	return stk.size();
}

int main() {

	vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};


	cout << minOperations(logs) << endl;
}