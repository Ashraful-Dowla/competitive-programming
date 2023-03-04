/*
https://codeforces.com/contest/1793/problem/C
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

	int arr[n+2];
	for(int i=1;i<=n;++i) {
		cin>>arr[i];
	}

	int mn=1,mx=n, l=1,r=n;
	while(l<r){
		bool chk1=false,chk2=false;
		if(arr[l]==mn){
			l++,mn++;
		}
		else if(arr[l]==mx){
			l++,mx--;
		}
		else chk1=true;

		if(arr[r]==mn){
			r--,mn++;
		}
		else if(arr[r]==mx){
			r--,mx--;
		}
		else chk2=true;

		if(chk1 && chk2) {
			cout<<l<<" "<<r<<endl;
			return ;
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