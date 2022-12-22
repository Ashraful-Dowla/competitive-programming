/*
https://codeforces.com/problemset/problem/520/B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e4+10;

ll n,m,level[4*N];
vector<ll> graph[4*N];
bool visited[4*N];

void calc(ll sum){
	if(visited[sum]) return ;

	if(sum<=2*m) {
		visited[sum]=true;
		graph[sum].push_back(2*sum);
		calc(2*sum);
	}
	if(sum-1>=0){
		visited[sum]=true;
		graph[sum].push_back(sum-1);
		calc(sum-1);
	}
}

void bfs(int src){
	queue<ll>q;

	q.push(src);
	visited[src]=true;

	while(!q.empty()) {
	    ll vertex = q.front();
	    q.pop();

	    for(auto val: graph[vertex]){
	    	if(!visited[val]){
	    		visited[val]=true;
	    		q.push(val);
	    		level[val]=level[vertex]+1;
	    	}
	    }
	}
}

int main(){
	cin>>n>>m;
	calc(n);

	memset(visited,false,sizeof(visited));
	bfs(n);

	cout<<level[m]<<endl;
}	