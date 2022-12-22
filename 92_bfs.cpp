#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>graph[N];
bool visited[N];
int level[N];

// complexity -> O(V+E)

// 13
// 1 2
// 1 3
// 1 13
// 2 5
// 3 4
// 5 6
// 5 7
// 5 8
// 8 12
// 4 9
// 4 10
// 10 11

void bfs(int source){
	queue<int>q;
	q.push(source);
	visited[source]=true;

	while(!q.empty()) {
	    int cur_vertex = q.front();
	    q.pop();
	    for(int child: graph[cur_vertex]){
	    	if(!visited[child]){
	    		q.push(child);
	    		visited[child]=true;
	    		level[child] = level[cur_vertex]+1;
	    	}
	    }
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;++i){
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	bfs(1);

	for(int i=1;i<=n;++i){
		cout<<i<<": "<<level[i]<<endl;
	}
}