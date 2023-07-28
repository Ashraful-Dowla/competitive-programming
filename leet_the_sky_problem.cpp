/*
https://leetcode.com/problems/the-skyline-problem/description/
*/
#include <bits/stdc++.h>
using namespace std;

//1->start, 0->end
struct node
{
	int x, y;
	bool position;
};

bool cmp(node a, node b) {
	if (a.x == b.x) {
		if (a.position == b.position) {
			if (a.position) return a.y > b.y;
			return a.y < b.y;
		}
		return a.position > b.position;
	}
	return a.x < b.x;
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

	vector<node>vec;
	for (auto v : buildings) {
		vec.push_back({v[0], v[2], true});
		vec.push_back({v[1], v[2], false});
	}

	sort(vec.begin(), vec.end(), cmp);

	// for (auto v : vec) {
	// 	cout << v.x << " " << v.y << " " << v.position << endl;
	// }

	multiset<int> ms;

	ms.insert(0);
	int mx_height = 0;

	vector<vector<int>> ans;

	for (auto v : vec) {

		if (v.position) ms.insert(v.y);
		else ms.erase(ms.find(v.y));

		int curr_mx_height = *(--ms.end());
		if (curr_mx_height != mx_height) {
			mx_height = curr_mx_height;

			vector<int> temp;
			temp.push_back(v.x);
			temp.push_back(mx_height);

			ans.push_back(temp);
		}
	}

	return ans;
}

int main() {

	// vector<vector<int>> buildings = {
	// 	{2, 9, 10},
	// 	{3, 7, 15},
	// 	{5, 12, 12},
	// 	{15, 20, 10},
	// 	{19, 24, 8}
	// };

	// vector<vector<int>> buildings = {
	// 	{0, 2, 3},
	// 	{2, 5, 3},
	// };

	vector<vector<int>> buildings = {
		{0, 5, 7},
		{5, 10, 7},
		{5, 10, 12},
		{10, 15, 7},
		{15, 20, 7},
		{15, 20, 12},
		{20, 25, 7}
	};

	auto res = getSkyline(buildings);

	for (auto v : res) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}