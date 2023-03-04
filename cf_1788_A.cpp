/*
https://codeforces.com/contest/1788/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;

	int cnt[3][n+2];
	memset(cnt,0,sizeof(cnt));

	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		cnt[x][i]=cnt[x][i-1]+1;
		int y = x==1 ? 2:1;
		cnt[y][i]=cnt[y][i-1];
	}

	int two = cnt[2][n];
	if(two==0) {
		cout<<1<<endl;
		return ;
	}
	else {
		for(int i=1;i<n;++i){
			if(2*cnt[2][i]==two){
				cout<<i<<endl;
				return ;
			}
		}
	}


	cout<<-1<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}