/*
https://codeforces.com/contest/1365/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

int n,m,ct_g,ct_b;
char arr[55][55];
bool visited[55][55];

vector<pr> directions = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1}
};

bool isValid(int x,int y){
	return x>=0 && x<n && y>=0 && y<m;
}

void dfs(int x,int y){

	visited[x][y]=true;
	if(arr[x][y]=='G') ct_g++;
	else if(arr[x][y]=='B') ct_b++;

	for(auto &val:directions){
		int _x = x+val.first;
		int _y = y+val.second;

		if(!isValid(_x,_y) || visited[_x][_y] || arr[_x][_y]=='#') continue;

		dfs(_x,_y);
	}
}

void prnt(){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}

int main(){
	int t;
	cin>>t;

	while(t--) {
	    cin>>n>>m;

	    int g=0;
	    for(int i=0;i<n;++i){
	    	for(int j=0;j<m;++j){
	    		cin>>arr[i][j];
	    		if(arr[i][j]=='G') g++;
	    	}
	    }

	    ct_g=ct_b=0;
		memset(visited,false,sizeof(visited));

	    for(int i=0;i<n;++i){
	    	for(int j=0;j<m;++j){
	    		if(arr[i][j]=='B'){
					for(auto &val:directions){
						int _i = i+val.first;
						int _j = j+val.second;

						if(!isValid(_i,_j) || arr[_i][_j]!='.') continue;
						arr[_i][_j]='#';
					}
	    		}
	    	}
	    }

	    // prnt();

	    if(arr[n-1][m-1]=='#'){
	    	cout<<(g==0 ? "Yes": "No")<<endl;
	    }
	    else {
	    	dfs(n-1,m-1);
	    	cout<<(ct_g==g && ct_b==0 ? "Yes": "No")<<endl;
	    }
	}
}