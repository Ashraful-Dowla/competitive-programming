/*
https://codeforces.com/contest/1808/problem/A
*/

//Author: Ashraful Dowla

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Faster ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define ld long double
#define vi vector<int> 
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

const int N=1e6+10;
const int MOD=1e9+7;

int calc(string s){
	int mn=10, mx=-1;
	for(int i=0;i<s.size();++i){
		mn = min(mn, s[i]-'0');
		mx = max(mx, s[i]-'0');
	}

	return mx-mn;
}	

void solve(){
	int l,r;
	cin>>l>>r;

	int mx=-1, ans;
	for(int i=l;i<=r && mx<9;++i){
		int val = calc(to_string(i));
		if(mx<val){
			ans=i;
			mx=val;
		}
	}

	prnt1(ans);
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}