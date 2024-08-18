/*
https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15
*/
#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {

	vector<int> ct(25, 0);

	for (int x : bills) {
		if (x == 5) {
			ct[x]++;
		}
		else if (x == 10) {
			if (ct[5] < 1) {
				return false;
			}
			ct[5]--;
			ct[x]++;
		}
		else {
			if (ct[5] > 0 && ct[10] > 0) {
				ct[5]--;
				ct[10]--;
			}
			else if (ct[5] > 2) {
				ct[5] -= 3;
			}
			else {
				return false;
			}
		}
	}

	return true;
}

int main() {

	vector<int> bills = {5, 5, 5, 10, 20};
	cout << lemonadeChange(bills) << endl;
}