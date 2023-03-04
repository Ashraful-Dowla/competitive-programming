/*
https://codeforces.com/contest/1786/problem/A2
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

	int a_w=0,a_b=0,b_w=0,b_b=0;
	a_w++,n--;

	int i=2, chk=0;
	while(n>=(2*i+1)){
		int val=2*i+1;
		int cnt=(val+1)/2;
		n-=val;
		if(!chk){
			b_b+=cnt;
			b_w+=(val-cnt);
		}
		else {
			a_w+=cnt;
			a_b+=(val-cnt);
		}
		chk=1-chk;
		i+=2;
	}

	if(n>0){
		int rem = (n+1)/2;
		if(chk){
			a_w+=rem;
			a_b+=(n-rem);
		}
		else {
			b_b+=rem;
			b_w+=(n-rem);
		}
	}

	cout<<a_w<<" "<<a_b<<" "<<b_w<<" "<<b_b<<endl;
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