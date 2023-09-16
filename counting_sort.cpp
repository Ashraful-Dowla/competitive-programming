#include <bits/stdc++.h>
using namespace std;

#define RANGE 300

//time complexity -> O(n+k)
int main() {
	char arr[] = "geeksforgeeks";
	int sz = sizeof(arr) / sizeof(arr[0]);
	char output[sz];

	int cnt[RANGE];
	memset(cnt, 0, sizeof(cnt));

	for (int i = 0; arr[i]; ++i) {
		++cnt[arr[i]];
	}

	for (int i = 1; i <= RANGE; ++i) {
		cnt[i] += cnt[i - 1];
	}

	for (int i = 0; arr[i]; ++i) {
		output[cnt[arr[i]] - 1] = arr[i];
		--cnt[arr[i]];
	}

	for (int i = 0; arr[i]; ++i) {
		arr[i] = output[i];
	}
	cout << arr << endl;
}