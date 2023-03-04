/*
https://codeforces.com/contest/1788/problem/C
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

	if(n%2==0) {
		cout<<"NO"<<endl;
		return ;
	}

	int l=(n+1)/2;
	int r=(1-n)/2;

	int a=1,b=n+l;
	cout<<"YES"<<endl;
	
	do{
		cout<<a<<" "<<b<<endl;
		a+=l, b+=r;
		swap(l,r);
	}while(--n);
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}