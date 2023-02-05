/*
https://codeforces.com/contest/1778/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const int MOD=1e9+7;

void solve(){
	int n;;
	cin>>n;

	ll arr[n];
	ll sum=0;

	for(int i=0;i<n;++i){
		cin>>arr[i];
		sum+=arr[i];
	}

	ll ans = sum;

	bool chk=false;
	for(int i=0;i+1<n;++i){
		if((arr[i]==-1 && arr[i+1]==1) || (arr[i]==1 && arr[i+1]==-1) ){
			chk=true;
			break;
		}
	}

	ll ans1 = sum;
	bool chk1 = false;
	for(int i=0;i+1<n;++i){
		if(arr[i]==-1 && arr[i+1]==-1){
			ans1+=4;
			if(chk) ans = max(ans,ans1);
			else ans = ans1;
			chk1=true;
			break;
		}
	}

	ll ans2 = sum;
	for(int i=0;i+1<n;++i){
		if(arr[i]==1 && arr[i+1]==1){
			ans2-=4;
			if(chk1) ans = max(ans,ans2);
			else if(chk) ans=max(ans,ans2);
			else ans = ans2;
			break;
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