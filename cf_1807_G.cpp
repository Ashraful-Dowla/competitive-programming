/*
https://codeforces.com/contest/1807/problem/G2
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

	vector<ll> vec(n);

	for(int i=0;i<n;++i){
		cin>>vec[i];
	}

	sort(vec.begin(),vec.end());

	if(vec[0]>1) {
		cout<<"NO"<<endl;
		return ;
	}

	ll sum=vec[0];

	for(int i=1;i<n;++i){
		if(vec[i]>sum){
			cout<<"NO"<<endl;
			return ;
		}
		sum+=vec[i];
	}

	cout<<"YES"<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}