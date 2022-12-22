/*
https://codeforces.com/problemset/problem/445/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

int n,m;
bool visited[105][105];

vector<string>vec;
vector<pr> directions = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

bool isValid(int x,int y){
	return x>=0 && x<n && y>=0 && y<m;
}

void dfs(int x,int y,char par_color){

	visited[x][y]=true;
	vec[x][y]=par_color;

	for(auto &val: directions){
		int _x = x+val.first;
		int _y = y+val.second;

		if(!isValid(_x,_y) || vec[_x][_y]!='.') continue;

		if(!visited[_x][_y]){
			char child_color = par_color=='B' ? 'W': 'B';
			dfs(_x,_y,child_color);
		}
	}
}

void prnt(){
	for(string &val: vec){
		for(char &ch:val){
			cout<<ch;
		}
		cout<<endl;
	}
}

void find_start_point(){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(vec[i][j]=='.'){
				dfs(i,j,'B');
			}
		}
	}
}

int main(){
	cin>>n>>m;

	for(int i=0;i<n;++i){
		string s;
		cin>>s;
		vec.push_back(s);
	}

	find_start_point();
	prnt();
}