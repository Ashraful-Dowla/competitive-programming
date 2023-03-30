/*
https://codeforces.com/problemset/problem/907/A
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
	int a,b,c,d;
	cin>>a>>b>>c>>d;

	if(c>d*2 || d>2*c || d>=b) cout<<-1<<endl;
	else cout<<2*a<<" "<<2*b<<" "<<max(c,d)<<endl;
}

int main(){
	Faster;

	solve();
}