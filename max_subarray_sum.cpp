#include <bits/stdc++.h>
using namespace std;

//time complexity -> O(n)
int main() {
	vector<int>v = { -1, 2, 4, -3, 5, 2, -5, 2};

	int sum = v[0], best = v[0];
	for (int i = 1; i < v.size(); ++i) {
		sum = max(v[i], sum + v[i]);
		best = max(best, sum);
	}
	cout << best << endl;
	return 0;
}