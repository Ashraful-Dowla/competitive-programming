/*
https://codeforces.com/contest/1806/problem/C
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
	int m;
	cin>>m;

	int n = 2*m;
	ll ans = 0;

	ll arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
		ans+=abs(arr[i]);
	}

	if(n==2){
		ans = min(ans,abs(arr[0]-arr[1]));
	}
	if(n==4){
		ll temp=0;
		for(int i=0;i<n;++i){
			temp+=abs(arr[i]-2);
		}
		ans = min(ans, temp);
	}
	if(n%4==0){
		ll temp=0;
		for(int i=0;i<n;++i){
			temp+=abs(arr[i]+1);
		}
		for(int i=0;i<n;++i){
			temp-=abs(arr[i]+1);
			temp+=abs(arr[i]-m);

			ans = min(ans,temp);
			
			temp-=abs(arr[i]-m);
			temp+=abs(arr[i]+1);
		}
	}

	cout<<ans<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}