/*
https://www.spoj.com/problems/NAKANJ/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;

int visited[8][8];
int level[8][8];
int INF = 1e9 + 10;

int getX(string s) {
	return s[0] - 'a';
}

int getY(string s) {
	return s[1] - '1';
}

bool isValid(int x, int y) {
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

vector<pr> movements = {
	{2, -1}, { -2, -1},
	{2, 1}, { -2, 1},
	{1, 2}, {1, -2},
	{ -1, 2}, { -1, -2}
};

int bfs(string src, string dest) {
	int srcX = getX(src);
	int srcY = getY(src);
	int destX = getX(dest);
	int destY = getY(dest);

	queue<pr>q;

	q.push({srcX, srcY});
	visited[srcX][srcY] = 1;
	level[srcX][srcY] = 0;

	while (!q.empty()) {
		pr v = q.front();
		int x = v.first, y = v.second;
		q.pop();

		for (auto movement : movements) {
			int childX = movement.first + x;
			int childY = movement.second + y;
			if (!isValid(childX, childY)) continue;
			if (!visited[childX][childY]) {
				q.push({childX, childY});
				visited[childX][childY] = 1;
				level[childX][childY] = level[x][y] + 1;
			}
		}
		if (level[destX][destY] != INF) break;
	}

	return level[destX][destY];
}

void reset() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			visited[i][j] = 0;
			level[i][j] = INF;
		}
	}
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		reset();
		string s1, s2;
		cin >> s1 >> s2;
		cout << bfs(s1, s2) << endl;
	}
}