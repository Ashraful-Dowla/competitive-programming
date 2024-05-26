/*
https://atcoder.jp/contests/abc278/tasks/abc278_e
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int H, W, N, h, w;
	cin >> H >> W >> N >> h >> w;

	int matrix[H][W], cnt[N + 1] = {0};

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> matrix[i][j];
			cnt[matrix[i][j]]++;
		}
	}

	vector<int> ans;
	for (int i = 0; i + h - 1 < H; ++i) {

		for (int j = i; j < i + h; ++j) {
			for (int k = 0; k < w; ++k) {
				cnt[matrix[j][k]]--;
			}
		}

		int ct = 0;
		for (int j = 1; j <= N; ++j) {
			if (cnt[j] > 0) {
				ct++;
			}
		}

		ans.push_back(ct);

		for (int j = w; j < W; ++j) {
			for (int k = i; k < i + h; ++k) {
				cnt[matrix[k][j]]--;
				cnt[matrix[k][j - w]]++;
			}
			ct = 0;
			for (int k = 1; k <= N; ++k) {
				if (cnt[k] > 0) {
					ct++;
				}
			}
			ans.push_back(ct);
		}

		for (int j = i; j < i + h; ++j) {
			for (int k = W - w; k < W; ++k) {
				cnt[matrix[j][k]]++;
			}
		}
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
		if ((i + 1) % (W - w + 1) == 0) {
			cout << endl;
		}
	}

}