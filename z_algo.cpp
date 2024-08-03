#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
string s, t;
int z[N];

void z_func() {
	int x = 0, y = 0, n = s.size();
	for (int i = 1; i < n; ++i) {
		z[i] = (y < i) ? 0 : min(y - i + 1, z[i - x]);

		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}

		if (i + z[i] - 1 > y) {
			x = i;
			y = i + z[i] - 1;
		}
	}
}

int main() {
	cin >> s;
	cin >> t;
	z_func();

	for (int i = 0; i < s.size(); ++i) {
		// if(z[i]==k) cout<<i-k<<endl;
		cout << z[i] << " ";
	}
	cout << endl;
}