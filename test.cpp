#include <bits/stdc++.h>
using namespace std;

int main() {

	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}

	cout << endl;

	stack<int> stk;

	stk.push(1);
	stk.push(2);
	stk.push(3);

	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}
}