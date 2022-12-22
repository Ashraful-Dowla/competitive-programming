/*
https://codeforces.com/contest/1245/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;

const int N=3000;
int parent[N],sz[N],power_cost[N], kilo_cost[N];
vector<pr>coordinates(N);

void make(int v){
	parent[v]=v;
}

int find(int v){
	if(parent[v]==v) return v;
	return parent[v] = find(parent[v]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a!=b){
		if(sz[a]<sz[b]) swap(a,b);
		parent[b]=a;
		sz[a]+=sz[b];
	}
} 

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>coordinates[i].first>>coordinates[i].second;
	}

	for(int i=1;i<=n;++i) cin>>power_cost[i];
	for(int i=1;i<=n;++i) cin>>kilo_cost[i];

	vector<pair<long long,pair<int,int>>>edges;

	for(int i=1;i<=n;++i){
		edges.push_back({power_cost[i], {0,i}});
		for(int j=i+1;j<=n;++j){
			int u_x = coordinates[i].first;
			int u_y = coordinates[i].second;

			int v_x = coordinates[j].first;
			int v_y = coordinates[j].second;

			int dist = abs(u_x-v_x)+abs(u_y-v_y);
			long long cost = dist*1LL*(kilo_cost[i]+kilo_cost[j]);

			edges.push_back({cost,{i,j}});
		}
	}
	sort(edges.begin(),edges.end());

	for(int i=1;i<=n;++i) make(i);

    vector<int>power_stations;
	vector<pair<int,int>>connections;

	long long total_cost = 0;
	for(auto &edge: edges){
		int cost = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;

		if(find(u)==find(v)) continue;
		Union(u,v);
		total_cost+=cost;

		if(u==0 || v==0) power_stations.push_back(max(u,v));
		else connections.push_back({u,v});
	}

	cout<<total_cost<<endl;
	cout<<power_stations.size()<<endl;
	for(auto &power_station: power_stations){
		cout<<power_station<<" ";
	}
	cout<<endl;
	cout<<connections.size()<<endl;
	for(auto &connection: connections){
		cout<<connection.first<<" "<<connection.second<<endl;
	}
}