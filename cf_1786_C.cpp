/*
https://codeforces.com/contest/1786/problem/C
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;

	vector<int> vec(n);
	for(int i=0;i<n;++i){
		cin>>vec[i];
	}

	sort(vec.begin(),vec.end());

	ll ans=0, cnt=1;
	for(int i=0;i<n;++i){
		if(vec[i]>=cnt){
			ans+=(vec[i]-cnt);
			cnt++;
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