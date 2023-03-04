/*
https://codeforces.com/contest/1795/problem/B
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
	int n,k;
	cin>>n>>k;

	int pf[100];
	memset(pf,0,sizeof(pf));

	vector<pair<int,int>> vec;
	for(int i=0;i<n;++i){
		int l,r;
		cin>>l>>r;
		vec.push_back({l,r});
		pf[l]++;
		pf[r+1]--;
	}

	for(int i=1;i<=50;++i){
		pf[i]+=pf[i-1];
	}

	for(auto pr: vec){
		int l = pr.first;
		int r = pr.second;
		if(l<=k && k<=r) continue;

		for(int i=l;i<=r;++i){
			pf[i]--;
		}
	}

	int mx=pf[k];
	for(int i=1;i<=50;++i){
		if(pf[i]>=mx && i!=k) {
			cout<<"NO"<<endl;
			return ;
		}
	}

	cout<<"YES"<<endl;
	// for(int i=1;i<=10;++i){
	// 	cout<<pf[i]<<" ";
	// }

	// cout<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}