#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;

stack<pr>stk;

void add(int new_element) {
	int new_min = stk.empty() ? new_element : min(stk.top().second, new_element);
	stk.push({new_element, new_min});
}

void rmv() {
	int remove_element = stk.top().first;
	stk.pop();
}

//O(1)
int getMin() {
	cout << stk.top().second << endl;
}

int main() {
	add(3);
	add(5);
	add(1);
	rmv();
	getMin();
}