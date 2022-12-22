/*
https://leetcode.com/problems/island-perimeter/
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int i,int j, vector<vector<int>>& grid, int &ans){

	int n=grid.size();
	int m=grid[0].size();

	if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){
		++ans;
		 return ;
	}
	if(grid[i][j]==2) return;
	grid[i][j]=2;

	dfs(i-1,j,grid,ans);
	dfs(i+1,j,grid,ans);
	dfs(i,j-1,grid,ans);
	dfs(i,j+1,grid,ans);
}


int islandPerimeter(vector<vector<int>>& grid) {
	int ans=0;
	int row=-1,col=-1;
	for(int i=0;i<grid.size();++i){
		for(int j=0;j<grid[i].size();++j){
			if(grid[i][j]) {
				row=i;
				col=j;
				break;
			}
		}
		if(row!=-1) break;
	}

	dfs(row,col,grid, ans);
	return ans;
}

int main(){
	vector<vector<int>>grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
	// vector<vector<int>>grid = {{1}};
	// vector<vector<int>>grid = {{1,0}};
	cout<<islandPerimeter(grid)<<endl;
}