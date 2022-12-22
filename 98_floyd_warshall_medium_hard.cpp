/*
https://codeforces.com/problemset/problem/295/B
*/
#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
long long dist[N][N];


int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>dist[i][j];
		}
	}
	vector<int> del_nodes(n);
	for(int i=0;i<n;++i){
		cin>>del_nodes[i];
	}
	reverse(del_nodes.begin(),del_nodes.end());

	vector<long long>ans;
	for(int k=0;k<n;++k){
		int k_v = del_nodes[k];
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				long long nwDist = dist[i][k_v] +  dist[k_v][j];
				dist[i][j] = min(dist[i][j], nwDist);
			}
		}
		long long sum=0;
		for(int i=0;i<=k;++i){
			for(int j=0;j<=k;++j){
				sum+=(dist[del_nodes[i]][del_nodes[j]]);
			}
		}
		ans.push_back(sum);
	}

	reverse(ans.begin(),ans.end());
	for(auto val: ans){
		cout<<val<<" ";
	}
}