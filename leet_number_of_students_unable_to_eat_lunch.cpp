/*
https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/submissions/1226422388/?envType=daily-question&envId=2024-04-08
*/
#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {

	queue<int> q;
	for (int x : students) {
		q.push(x);
	}

	stack<int> stk;
	for (int i = sandwiches.size() - 1; i >= 0; --i) {
		stk.push(sandwiches[i]);
	}

	int cnt = 0;
	while (cnt != q.size()) {

		int p = q.front();
		q.pop();

		if (p == stk.top()) {
			cnt = 0;
			stk.pop();
		}
		else {
			cnt++;
			q.push(p);
		}
	}

	return q.size();
}

int main() {

	// vector<int> students = {1, 1, 0, 0};
	// vector<int> sandwiches = {0, 1, 0, 1};

	vector<int> students = {1, 1, 1, 0, 0, 1};
	vector<int> sandwiches = {1, 0, 0, 0, 1, 1};

	cout << countStudents(students, sandwiches) << endl;
}