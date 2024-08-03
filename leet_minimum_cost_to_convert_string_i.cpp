/*
https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2024-07-27
*/
#include <bits/stdc++.h>
using namespace std;

long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

	long long dis[26][26];

	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			dis[i][j] = 1e18;
			if (i == j) dis[i][j] = 0;
		}
	}

	for (int i = 0; i < original.size(); ++i) {
		dis[original[i] - 'a'][changed[i] - 'a'] =
		    min(dis[original[i] - 'a'][changed[i] - 'a'], 1LL * cost[i]);
	}

	for (int k = 0; k < 26; ++k) {
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < source.size(); ++i) {
		long long cst = dis[source[i] - 'a'][target[i] - 'a'];
		if (cst == 1e18) {
			return -1;
		}
		ans += cst;
	}

	return ans;

}

int main() {

	string source = "abcd";
	string target = "acbe";
	vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
	vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
	vector<int> cost = {2, 5, 5, 1, 2, 20};

	cout << minimumCost(source, target, original, changed, cost) << endl;
}