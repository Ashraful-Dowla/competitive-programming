/*
https://codeforces.com/contest/1778/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const int MOD=1e9+7;

void solve(){
	int n,m,d;
	cin>>n>>m>>d;

	int p[n+2],a[n+2];
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		p[x]=i;
	}

	for(int i=1;i<=m;++i){
		cin>>a[i];
	}

	int ans=MOD;
	for(int i=1;i<m;++i){
		int x = a[i], y = a[i+1];
		if(p[x]>p[y] || p[y]>p[x]+d){
			ans = 0;
			break;
		}
		else {
			ans = min(ans, p[y]-p[x]);
			int mv = p[x]+d-p[y]+1;
			if(mv<=(p[x]-1+n-p[y])) {
				ans = min(ans, mv);
			}
		}
	}

	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}