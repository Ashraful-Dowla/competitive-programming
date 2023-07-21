/*
https://leetcode.com/problems/course-schedule-ii/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool visited[2005], in_stack[2005];
vector<int> graph[2005];
stack<int> stk;

bool dfs(int v) {

	if (in_stack[v]) return true;
	if (visited[v]) return false;

	visited[v] = in_stack[v] = true;

	bool is_loop_exists = false;
	for (int child : graph[v]) {
		is_loop_exists |= dfs(child);
	}

	in_stack[v] = false;

	return is_loop_exists;
}

void topological_sort(int v) {

	visited[v] = true;

	for (int child : graph[v]) {
		if (visited[child]) continue;
		topological_sort(child);
	}

	stk.push(v);
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

	vector<int> ans;
	for (auto p : prerequisites) {
		graph[p[1]].push_back(p[0]);
	}

	for (int i = 0; i < numCourses; ++i) {
		if (dfs(i)) return ans;
	}

	memset(visited, false, numCourses);

	for (int i = 0; i < numCourses; ++i) {
		if (visited[i]) continue;
		topological_sort(i);
	}

	while (!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
	}

	return ans;
}

int main() {

	int numCourses = 4;
	vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

	// int numCourses = 2;
	// vector<vector<int>> prerequisites = {{1, 0}};

	// int numCourses = 1;
	// vector<vector<int>> prerequisites = {};

	// int numCourses = 3;
	// vector<vector<int>> prerequisites = {{0, 2}, {1, 2}, {2, 0}};

	// int numCourses = 3;
	// vector<vector<int>> prerequisites = {{1, 0}};

	auto res = findOrder(numCourses, prerequisites);

	for (auto v : res) {
		cout << v << " ";
	}
}