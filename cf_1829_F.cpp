//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1829/problem/F
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define vi vector<int> 
#define vs vector<string>
#define vb vector<bool> 
#define pii pair<int,int>
#define pll pair<ll,ll>


#define pb push_back
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl;
#define prnt2(x,y) cout<<x<<" "<<y<<endl;

const int N=2e2+10;
const int MOD=1e9+7;


void solve(){
	int n,m;
	cin>>n>>m;

	vi graph[N];
	for(int i=0;i<m;++i){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i=1;i<=n;++i){
		set<int> s;
		for(auto v: graph[i]){
			s.insert(graph[v].size());
		}

		if(s.size()==1 && *s.begin()>2 && graph[i].size()>1){
			prnt2(graph[i].size(), *s.begin()-1);
			break;
		}
	}	
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}