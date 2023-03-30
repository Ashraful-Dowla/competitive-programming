/*
https://codeforces.com/problemset/problem/876/B
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

int cnt[N];

void solve(){
	int n,k,m;
	cin>>n>>k>>m;

	vector<int> vec(n),rem(n);

	int mx=-1,rm;
	for(int i=0;i<n;++i){
		cin>>vec[i];
		int x = vec[i]%m;
		rem[i]=x;
		++cnt[x];
		if(mx<cnt[x]){
			mx=cnt[x];
			rm=x;
		}
	}

	if(mx<k){
		cout<<"No"<<endl;
		return ;
	}

	cout<<"Yes"<<endl;
	for(int i=0;i<n && k;++i){
		if(rem[i]==rm){
			cout<<vec[i]<<" ";
			k--;
		}
	}
}

int main(){
	Faster;

	solve();
}