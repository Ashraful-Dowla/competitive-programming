/*
https://www.codechef.com/problems/REVERSE
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

const int N=1e5+10;
const int INF=1e9+10;

vector<pr>graph[N];
vector<int>level(N,INF);
int n,m;

int bfs(){
	deque<int> dq;
	dq.push_back(1);
	level[1]=0;

	while(!dq.empty()){
		int cur_v = dq.front();
		dq.pop_front();

		for(auto child : graph[cur_v]){
			int child_v = child.first;
			int wt = child.second;
			if(level[cur_v]+wt<level[child_v]){ // visited check by level
				level[child_v] = level[cur_v] + wt;
				if(wt==1) dq.push_back(child_v);
				else dq.push_front(child_v);
			}
		}
	}
	return level[n] == INF ? -1: level[n];
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int x,y;
		cin>>x>>y;
		if(x==y) continue;
		graph[x].push_back({y,0});
		graph[y].push_back({x,1});
	}

	cout<<bfs()<<endl;
}