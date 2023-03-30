/*
https://codeforces.com/contest/1806/problem/B
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

	int ct_z=0, ct=0;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(!x) ct_z++;
		else if(x!=1) ct++; 
	}

	if(ct_z<=(n+1)/2) cout<<0<<endl;
	else if(ct_z==n || ct) cout<<1<<endl;
	else cout<<2<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}