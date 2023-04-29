//Author: Ashraful Dowla
/*
https://codeforces.com/contest/1821/problem/C
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
	string s;
	cin>>s;

	int mn=INT_MAX;
	for(char ch='a'; ch<='z'; ++ch){

		int ct=0,mx=0;
		for(int i=0;i<s.size();++i){
			if(s[i]==ch) ct=0;
			else mx = max(mx, ++ct);
		}
		mn = min(mn, mx);
	}

	if(mn==0) prnt1(mn);
	else {
		int ans=0;
		while(mn>1){
			mn/=2;
			ans++;
		}
		prnt1(ans+1);
	}
}

int main(){
	Faster;

	int t;
	cin>>t;

	while(t--){
	   solve();
	}
}