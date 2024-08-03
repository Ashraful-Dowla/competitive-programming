#include <bits/stdc++.h>
using namespace std;

// int findTheWinner(int n, int k) {

// 	vector<bool> taken(n + 1, false);

// 	int m = n, ct = 0, i = 1;
// 	while (m > 1) {

// 		if (!taken[i]) {
// 			ct++;
// 		}

// 		if (ct == k) {
// 			taken[i] = true;
// 			ct = 0, m--;
// 		}

// 		if ((i + 1) % n == 0) {
// 			i = n;
// 		}
// 		else {
// 			i = (i + 1) % n;
// 		}
// 	}

// 	for (int i = 1; i <= n; ++i) {
// 		if (!taken[i]) {
// 			return i;
// 		}
// 	}
// }

int findTheWinner(int n, int k) {


	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		q.push(i);
	}

	while (q.size() > 1) {

		for (int i = 0; i < k - 1; ++i) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}

	return q.front();
}

int main() {

	int n = 5, k = 2;
	// int n = 6, k = 5;
	cout << findTheWinner(n, k) << endl;
}