/*
https://leetcode.com/problems/flood-fill/
*/
#include <bits/stdc++.h>
using namespace std;


void dfs(int i, int j, int iniColor, int newColor, vector<vector<int>>& image){
	int n = image.size();
	int m = image[0].size();

	if(i<0 || j<0) return;
	if(i>=n || j>=m) return;
	if(image[i][j]!=iniColor) return ;

	image[i][j] = newColor;

	dfs(i-1,j, iniColor, newColor, image);
	dfs(i+1,j, iniColor, newColor, image);
	dfs(i,j-1, iniColor, newColor, image);
	dfs(i,j+1, iniColor, newColor, image);	
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int iniColor = image[sr][sc];
    if(iniColor!=color) dfs(sr,sc, iniColor, color, image);
	return image;
}

int main(){
	vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
	floodFill(image,1,1,2);


	for(auto row: image){
		for(int val: row){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}