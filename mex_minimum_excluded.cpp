#include <bits/stdc++.h>
using namespace std;

// time complexity -> O(N*logN)
int mex(vector<int> &a) {

	set<int> s(a.begin(), a.end());

	int res = 0;
	while (s.count(res)) {
		res++;
	}

	return res;
}


int main() {

	vector<int> a = {0, 1, 2, 4, 5};
	// vector<int> a = {0, 1, 2, 3, 4};
	// vector<int> a = {1, 2, 3, 4, 5};

	cout << mex(a) << endl;
}