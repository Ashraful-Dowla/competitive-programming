/*
https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

const int N=1e3+10;
const int INF=1e9+10;

int val[N][N];
int visited[N][N];
int level[N][N];
int n,m;

vector<pr> movments = {
	{0,-1},{0,1},{-1,0},{1,0},
	{-1,-1},{1,1},{-1,1},{1,-1}
};

bool isValid(int i, int j){
	return i>=0 && j>=0 && i<n && j<m;
}

int bfs(){
	int mx=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			mx = max(mx, val[i][j]);
		}
	}
	queue<pr>q;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(mx==val[i][j]){
				q.push({i,j});
				visited[i][j]=1;
				level[i][j]=0;
			}
		}
	}

	int ans=0;
	while(!q.empty()){
		auto v = q.front();
		int v_x = v.first;
		int v_y = v.second;
		q.pop();

		for(auto movement: movments){
			int childX = v_x + movement.first;
			int childY = v_y + movement.second;
			if(!isValid(childX,childY) || visited[childX][childY]) continue;
			q.push({childX, childY});
			visited[childX][childY]=1;
			level[childX][childY] = level[v_x][v_y] + 1;
			ans = max(ans, level[childX][childY]);
		}
	}

	return ans;
}

void reset(){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			visited[i][j]=0;
			level[i][j]=INF;
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--) {
	   cin>>n>>m;
	   reset();
	   for(int i=0;i<n;++i){
	   	  for(int j=0;j<m;++j){
	   	  	cin>>val[i][j];
	   	  }
	   }
	   cout<<bfs()<<endl;
	}
}