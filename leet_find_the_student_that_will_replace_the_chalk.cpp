/*
https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/?envType=daily-question&envId=2024-09-02
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool can(vector<int> &chalk, int k, ll t) {

	ll sum = 0;
	for (int x : chalk) {
		ll r = x * 1LL * t;
		if (sum + r > k) {
			return false;
		}
		sum += r;
	}

	return true;
}

int chalkReplacer(vector<int>& chalk, int k) {


	ll sum = accumulate(chalk.begin(), chalk.end(), 0LL);
	ll lo = 1, hi = 1e9, t = 0;

	while (lo <= hi) {

		ll mid = (lo + hi) / 2;

		if (can(chalk, k, mid)) {
			t = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}

	k -= sum * t;

	sum = 0;
	int idx = 0;
	for (int i = 0; i < chalk.size(); ++i) {
		if (sum + chalk[i] > k) {
			idx = i;
			break;
		}
		sum += chalk[i];
	}

	return idx;
}

int main() {

	vector<int> chalk = {5, 1, 5};
	int k = 22;

	cout << chalkReplacer(chalk, k) << endl;
}