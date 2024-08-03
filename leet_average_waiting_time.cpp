/*
https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09
*/
#include <bits/stdc++.h>
using namespace std;

double averageWaitingTime(vector<vector<int>>& customers) {

	int n = customers.size();
	double time = customers[0][0] + customers[0][1];
	double ans = time - customers[0][0];

	for (int i = 1; i < n; ++i) {
		double st = customers[i][0], wait = customers[i][1];

		if (st < time) {
			ans += time - st + wait;
			time += wait;
		}
		else {
			ans += wait;
			time = st + wait;
		}
	}

	return ans / n;
}

int main() {

	vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};
	cout << averageWaitingTime(customers) << endl;
}