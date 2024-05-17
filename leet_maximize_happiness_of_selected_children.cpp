/*
https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2024-05-09
*/
#include <bits/stdc++.h>
using namespace std;

long long maximumHappinessSum(vector<int>& happiness, int k) {

	multiset<int> ms;
	for (int x : happiness) {
		ms.insert(x);
	}

	long long ans = 0;
	for (int i = 0; i < k; ++i) {
		int x = *ms.rbegin();
		ans += max(0, x - i);
		ms.erase(ms.find(x));
	}

	return ans;
}

int main() {

	// vector<int> happiness = {1, 2, 3};
	// int k = 2;

	// vector<int> happiness = {1, 1, 1, 1};
	// int k = 2;

	vector<int> happiness = {2, 3, 4, 5};
	int k = 1;

	cout << maximumHappinessSum(happiness, k) << endl;
}