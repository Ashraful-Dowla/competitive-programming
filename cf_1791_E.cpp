/*
https://codeforces.com/contest/1791/problem/E
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;

	vector<ll> vec(n);
	ll sum=0;
	int neg=0;
	for(int i=0;i<n;++i){
		cin>>vec[i];
		if(vec[i]<0){
			++neg;
			vec[i]*=-1;
		}
		sum+=vec[i];
	}

	sort(vec.begin(),vec.end());
	if(neg&1) sum-=2*vec[0];
	cout<<sum<<endl;
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