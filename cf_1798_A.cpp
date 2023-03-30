/*
https://codeforces.com/contest/1798/problem/A
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vi vector<int> 

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"

const int N=1e5+10;
const int MOD=1e9+7;

bool chk(vi a, vi b){
	int n = a.size();

	bool ok=true;
	for(int i=0;i<n-1;++i){
		if(a[i]<=a[n-1] && b[i]<=b[n-1]) continue;
		swap(a[i],b[i]);
		if(a[i]<=a[n-1] && b[i]<=b[n-1]) continue;
		ok=false;
		break;
	}

	return ok;
}

void solve(){
	int n;
	cin>>n;

	vi a(n),b(n);

	for(int i=0;i<n;++i){
		cin>>a[i];
	}

	for(int i=0;i<n;++i){
		cin>>b[i];
	}

	bool res = chk(a,b);
	if(res) {
		cout<<"Yes"<<endl;
		return ;
	}	

	swap(a[n-1],b[n-1]);
	res = chk(a,b);

	cout<<(res? "Yes": "No")<<endl;
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}