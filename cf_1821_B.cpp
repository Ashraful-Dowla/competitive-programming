//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1821/problem/B
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define vi vector<int> 
#define vll vector<ll> 
#define vs vector<string>
#define vb vector<bool> 
#define pii pair<int,int>
#define pll pair<ll,ll>


#define pb push_back
#define all(c) (c).begin(),(c).end()

//debug
#define vec_prnt(v) for(auto x: v) { cout<<x<<" "; } cout<<"\n"
#define prnt1(x) cout<<x<<endl
#define prnt2(x,y) cout<<x<<" "<<y<<endl

const int N=1e5+10;
const int MOD=1e9+7;

void solve(){
	int n;
	cin>>n;

	int a[n],b[n];

	for(int i=0;i<n;++i) cin>>a[i]; 
	for(int i=0;i<n;++i) cin>>b[i];

	int l=0,r=n-1;

	while(l<n && a[l]==b[l]){
		l++;
	} 

	while(r>l && a[r]==b[r]){
		r--;
	}

	while(l>=1 && b[l]>=b[l-1]){
		l--;
	}

	while(r+1<n && b[r]<=b[r+1]){
		r++;
	}

	prnt2(++l,++r);
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}