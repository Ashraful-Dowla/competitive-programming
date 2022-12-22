/*
https://codeforces.com/problemset/problem/377/A
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

const int N=505;
int n,m,k,ct,w_ct;
bool visited[N][N];
char graph[N][N];

vector<pr> directions = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

bool isValid(int x,int y){
	return x>=0&&x<n && y>=0 && y<m;
}

void dfs(int x,int y){
	visited[x][y]=true;

	for(auto &val: directions){
		int _x = x+val.first;
		int _y = y+val.second;

		if(!isValid(_x,_y) || visited[_x][_y] || graph[_x][_y]!='.'){
			 continue;
		}
		dfs(_x,_y);
	}

	if(k) {
		graph[x][y]='X';
		k--;
	}
}

void prnt(){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cout<<graph[i][j];
		}
		cout<<endl;
	}
}

int main(){
	cin>>n>>m>>k;

	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>graph[i][j];		
		}
	}

	bool chk=false;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(graph[i][j]=='.'){
				dfs(i,j);
				chk=true;
				break;
			}
		}
		if(chk) break;
	}

	prnt();
}