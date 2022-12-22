#include <bits/stdc++.h>
using namespace std;


// 7 11
// 1 2 3
// 3 1 3
// 1 4 3
// 3 4 1
// 3 5 2
// 4 5 2
// 4 6 6
// 6 7 9
// 5 7 1
// 2 3 4
// 5 2 1
// 1 7

//ans:5

typedef vector<int> vi;
const int MAX_V=100,INF=1e9;

int res[MAX_V][MAX_V],mf,f,s,t;
vi p;

void augment(int v,int minEdge){
	if(v==s) {
		f = minEdge;
		return ;
	}
	else if(p[v]!=-1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v]-=f;
		res[v][p[v]]+=f;
	}
}

//time complexity -> O(V*E^2)
int max_flow(){
	mf=0;

	while(true) {
	    f=0;

	    vi dist(MAX_V,INF);
	    dist[s]=0;
	    queue<int>q;
	    q.push(s);
	    p.assign(MAX_V,-1);

	    while(!q.empty()){
	    	int u = q.front();
	    	q.pop();
	    	if(u==t) break;

	    	for(int v=0;v<MAX_V;++v){
	    		if(res[u][v]>0 && dist[v] == INF){
	    			dist[v] = dist[u]+1;
	    			q.push(v);
	    			p[v]=u;
	    		}
	    	}
	    }

	    augment(t,INF);
	    if(f==0) break;
	    mf+=f;
	}

	return mf;
}

int main(){
	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;++i){
		int u,v,cst;
		cin>>u>>v>>cst;
		res[u][v]=cst;
	}

	cin>>s>>t;

	cout<<max_flow()<<endl;
}