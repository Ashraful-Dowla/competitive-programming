/*
https://leetcode.com/problems/course-schedule/description/
*/
#include <bits/stdc++.h>
using namespace std;

bool visited[5005], in_stack[5005];
vector<int> graph[5005];

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


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

	for (auto p : prerequisites) {
		graph[p[1]].push_back(p[0]);
	}

	for (int i = 0; i < numCourses; ++i) {
		if (visited[i]) continue;

		if (dfs(i)) return false;
	}

	return true;
}

int main() {

	// int numCourses = 2;
	// vector<vector<int>> prerequisites = {{1, 0}};

	// int numCourses = 2;
	// vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};

	// int numCourses = 3;
	// vector<vector<int>> prerequisites = {{1, 0}, {1, 2}, {0, 1}};

	int numCourses = 2;
	vector<vector<int>> prerequisites = {{0, 1}};


	cout << canFinish(numCourses, prerequisites);
}