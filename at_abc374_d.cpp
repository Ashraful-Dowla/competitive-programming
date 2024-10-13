/*
https://atcoder.jp/contests/abc374/tasks/abc374_d
*/
#include <bits/stdc++.h>
using namespace std;

double dis(double a, double b, double c, double d) {
	return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main() {
	int n;
	cin >> n;
	double s, t;
	cin >> s >> t;

	vector<pair<pair<double, double>, pair<double, double>>> segments(n);

	for (int i = 0; i < n; ++i) {
		double a, b, c, d;
		cin >> a >> b >> c >> d;
		segments[i] = {{a, b}, {c, d}};
	}

	double min_time = 1e18;

	vector<int> perm(n);
	for (int i = 0; i < n; ++i) {
		perm[i] = i;
	}

	do {

		for (int mask = 0; mask < (1 << n); ++mask) {

			double curr_time = 0;
			double x = 0, y = 0;

			for (int i = 0; i < n; ++i) {
				int idx = perm[i];
				pair<double, double> start, end;

				if (mask & (1 << i)) {
					start = segments[idx].first;
					end = segments[idx].second;
				} else {
					start = segments[idx].second;
					end = segments[idx].first;
				}

				curr_time += dis(x, y, start.first, start.second) / s;

				curr_time += dis(start.first, start.second,
				                 end.first, end.second) / t;

				x = end.first;
				y = end.second;
			}

			min_time = min(min_time, curr_time);
		}

	} while (next_permutation(perm.begin(), perm.end()));


	cout << fixed << setprecision(12) << min_time << endl;

	return 0;
}
